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

#define MAX_A 100001

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> arr(MAX_A);
  int i, a;
  for (i=1; i<=n; ++i) {
    cin >> a;
    arr[a].pb(i);
  }

  int j, lim, d;
  vector<std::pair<int, int>> diff;
  for (i=1; i<MAX_A; ++i) {
    if (arr[i].empty())
      continue;
    if (arr[i].size() == 1) {
      diff.pb(mp(i, 0));
      continue;
    }

    lim = arr[i].size();
    d = arr[i][1] - arr[i][0];
    for (j=2; j<lim; ++j) {
      if ((arr[i][j] - arr[i][j-1]) != d) {
        d = -1;
        break;
      }
    }

    if (d != -1) {
      diff.pb(mp(i, d));
    }
  }

  lim = diff.size();
  cout << lim << "\n";
  for (i=0; i<lim; ++i) {
    cout << diff[i].first << " " << diff[i].second << "\n";
  }

  cout << std::flush;
  return 0;
}
