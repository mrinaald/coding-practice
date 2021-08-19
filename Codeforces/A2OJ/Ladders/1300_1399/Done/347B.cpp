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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> arr(n, 0);
  int i;
  int num_fixed = 0;
  for (i=0; i<n; ++i) {
    cin >> arr[i];
    if (arr[i] == i) {
      num_fixed++;
    }
  }

  if (num_fixed == n) {
    cout << n << endl;
    return 0;
  }

  for (i=0; i<n; ++i) {
    if (arr[i] == i) {
      continue;
    }

    if (arr[arr[i]] == i) {
      num_fixed++;
      break;
    }
  }

  cout << num_fixed + 1 << "\n";

  cout << std::flush;
  return 0;
}
