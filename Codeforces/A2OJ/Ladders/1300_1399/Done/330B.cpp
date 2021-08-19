/*
 * Hint taken from tutorial blog: https://codeforces.com/blog/entry/8417
 */
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

  int n, m;
  cin >> n >> m;

  int i, a, b;
  vector<bool> arr(n+1, true);
  for (i=0; i<m; ++i) {
    cin >> a >> b;
    arr[a] = false;
    arr[b] = false;
  }

  a = 0;
  for (i=1; i<=n; ++i) {
    if (arr[i]) {
      a = i;
      break;
    }
  }

  cout << n-1 << "\n";
  for (i=1; i<=n; ++i) {
    if (i == a) {
      continue;
    } else if (i < a) {
      cout << i << " " << a << "\n";
    } else {
      cout << a << " " << i << "\n";
    }
  }

  cout << std::flush;
  return 0;
}
