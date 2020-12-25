#include <iostream>

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

  int l, r;
  int lc = 0;
  int rc = 0;

  for (int i=0; i<n; ++i) {
    cin >> l >> r;
    if (l == 1)
      ++lc;
    if (r == 1)
      ++rc;
  }

  int lcd = n - lc;
  int rcd = n - rc;

  int ans = 0;
  if (lc < lcd)
    ans += lc;
  else
    ans += lcd;

  if (rc < rcd)
    ans += rc;
  else
    ans += rcd;

  cout << ans << "\n";

  cout << std::flush;
  return 0;
}
