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

  vector<string> grid(n);
  int i, j;
  for (i=0; i<n; ++i) {
    cin >> grid[i];
  }

  char s;
  int cnt = 0;
  for (i=0; i<n; ++i) {
    for (j=0; j<m; ++j) {
      s = grid[i][j];
      if (s == 'W' || s == '.')
        continue;
      // This cell is a pig
      // check whether any wolf is around. If it is, cnt++
      if (j > 0) {
        if (grid[i][j-1] == 'W') {
          cnt++;
          grid[i][j-1] = '.';
        }
      }
      if (i > 0) {
        if (grid[i-1][j] == 'W') {
          cnt++;
          grid[i-1][j] = '.';
        }
      }
      if (j < m-1) {
        if (grid[i][j+1] == 'W') {
          cnt++;
          grid[i][j+1] = '.';
        }
      }
      if (i < n-1) {
        if (grid[i+1][j] == 'W') {
          cnt++;
          grid[i+1][j] = '.';
        }
      }
    }
  }

  cout << cnt << endl;

  cout << std::flush;
  return 0;
}
