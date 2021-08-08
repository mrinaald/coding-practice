/*
 * Solution hints taken from:
 * 1) https://codeforces.com/blog/entry/12513
 * 2) https://github.com/AkashChandrakar/codeforces-solutions/blob/master/c%2B%2B/437-C-13875747.cpp
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

  vector<int> value(n, 0);
  int i;
  for (i=0; i<n; ++i) {
    cin >> value[i];
  }

  int x, y;
  llong total_cost = 0;
  for (i=0; i<m; ++i) {
    cin >> x >> y;
    --x; --y;   // Converting to 0-based indexing
    total_cost += min(value[x], value[y]);
  }

  cout << total_cost << "\n";

  cout << std::flush;
  return 0;
}
