/*
 * The below implementation is O(NlogN), but can be done faster in O(N)
 */
#include <iostream>
#include <vector>
#include <algorithm>

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

  int i;
  vector<int> arr(n+1, 0);
  for (i=1; i<=n; ++i) {
    cin >> arr[i];
  }

  sort(all(arr));

  for (i=1; i<=n; ++i) {
    if (i != arr[i]) {
      break;
    }
  }

  cout << i << endl;

  cout << std::flush;
  return 0;
}
