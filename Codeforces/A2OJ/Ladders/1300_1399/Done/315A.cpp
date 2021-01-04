#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MAX_BOTTLES 1000

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> arr(MAX_BOTTLES + 1, vector<int>());
  vector<int> count(MAX_BOTTLES + 1, 0);
  int i, a, b;

  for (i=0; i<n; ++i) {
    cin >> a >> b;

    arr[a].pb(b);
  }

  set<int> can_open;
  for (a=1; a<=MAX_BOTTLES; ++a) {
    if (arr[a].empty())
      continue;

    b = arr[a].size();
    for (i=0; i<b; ++i) {
      if (a != arr[a][i]) {
        if (arr[arr[a][i]].size() > 0) {
          can_open.insert(arr[a][i]);
        }
      }
      else {
        count[a]++;
      }
    }
  }

  for (a=1; a<=MAX_BOTTLES; ++a) {
    if (arr[a].empty())
      continue;

    if (can_open.find(a) != can_open.end()) {
      n -= arr[a].size();
    }
    else {
      if (count[a] == 1) {
        n -= (arr[a].size() - 1);
      }
      else if (count[a] > 1) {
        n -= arr[a].size();
      }
    }
  }

  cout << n << "\n";
  cout << std::flush;
  return 0;
}
