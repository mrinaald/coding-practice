#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MAX_N 100002
#define MAX_P 31

vector<int> smallest(MAX_N);

void rec(vector<int>& arr, int n, int x) {
  if (x <= 0) {
    bool take_this = false;
    int i;
    for (i=0; i<n; ++i) {
      if (smallest[i] > arr[i]) {
        take_this = true;
        break;
      }
      else if (smallest[i] < arr[i]) {
        take_this = false;
        break;
      }
    }

    if (take_this) {
      for (i=0; i<n; ++i) {
        smallest[i] = arr[i];
      }
    }
    return;
  }

  int i, j, p;
  int orig_i, orig_j;
  for (i=0; i<n; ++i) {
    orig_i = arr[i];
    for (j=i+1; j<n; ++j) {
      orig_j = arr[j];

      for (p=0; p<=MAX_P; ++p) {

        arr[i] = arr[i] ^ (1 << p);
        arr[j] = arr[j] ^ (1 << p);

        rec(arr, n, x-1);

        arr[i] = orig_i;
        arr[j] = orig_j;
      }
    }
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, N, X;
  cin >> T;

  vector<int> arr(MAX_N);
  vector<int> temp(MAX_N);
  int i, j, p;

  while (T--) {
    cin >> N >> X;

    for (i=0; i<N; ++i) {
      cin >> arr[i];
      temp[i] = arr[i];
      smallest[i] = 100;
    }

    // for (i=0; i<N; ++i) {
    //   cout << temp[i] << " ";
    // }
    // cout << endl;
    rec(temp, N, X);

    for (i=0; i<N; ++i) {
      cout << smallest[i] << " ";
    }
    // cout << "\n";
    cout << endl;
  }

  cout << std::flush;
  return 0;
}
