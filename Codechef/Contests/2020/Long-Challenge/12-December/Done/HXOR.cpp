#include <iostream>
#include <cmath>
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
#define MAX_P 32

int N, X;
vector<int> pow2(MAX_P);
vector<int> p_arr(MAX_P);
int p_count = 0;

void compute_special_ans(vector<int> &arr);
void compute_ans(vector<int> &arr);

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  vector<int> arr(MAX_N);
  int i;

  for (i=0; i<MAX_P; ++i) {
    pow2[i] = 1 << i;
  }

  while (T--) {
    cin >> N >> X;

    for (i=0; i<N; ++i) {
      cin >> arr[i];
    }

    if (N == 2) {
      compute_special_ans(arr);
    }
    else {
      compute_ans(arr);
    }

    for (i=0; i<N; ++i) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }

  cout << std::flush;
  return 0;
}


void compute_special_ans(vector<int> &arr) {
  int p;

  while ((arr[0] > 0) && (X > 0)) {
    p = (int) log2(arr[0]);
    arr[0] = arr[0] ^ pow2[p];
    arr[1] = arr[1] ^ pow2[p];
    X--;
  }

  if (X & 1) {
    arr[0] = arr[0] ^ 1;
    arr[1] = arr[1] ^ 1;
  }
}


void compute_ans(vector<int> &arr) {
  int i, p;

  for (i=0; i<MAX_P; ++i) {
    p_arr[i] = 0;
  }
  p_count = 0;

  for (i=0; i<N; ++i) {
    if ((p_count == 0) && (X == 0))
      return;

    p = (int) log2(arr[i]);
    while (p >= 0) {
      if ((arr[i] & pow2[p]) == 0) {
        --p;
        continue;
      }
      if (p_arr[p] > 0) {
        arr[i] = arr[i] ^ pow2[p];
        p_arr[p] -= 1;
        --p_count;
      }
      else if (X > 0){
        arr[i] = arr[i] ^ pow2[p];
        p_arr[p] += 1;
        ++p_count;
        X--;
      }
      --p;
    }
  }

  if (p_count > 0) {
    for (p=0; p<MAX_P; ++p) {
      if (p_arr[p] > 0) {
        arr[N-1] = arr[N-1] ^ pow2[p];
        p_arr[p] = 0;
      }
    }
    p_count = 0;
  }
}
