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

#define MAX_NUM 5000

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  cin >> n;

  int n2 = 2 * n;
  vector<vector<int>> cards(MAX_NUM + 1, vector<int>());
  int i, c;

  for (i=1; i<=n2; ++i) {
    cin >> c;
    cards[c].pb(i);
  }

  bool is_possible = true;
  for (i=1; i<=MAX_NUM; ++i) {
    if (cards[i].empty())
      continue;
    if (cards[i].size() & 1) {
      is_possible = false;
      break;
    }
  }

  if (!is_possible) {
    cout << "-1\n";
  }
  else {
    for (i=1; i<=MAX_NUM; ++i) {
      if (cards[i].empty())
        continue;
      for (c=0; c<cards[i].size(); c+=2) {
        cout << cards[i][c] << " " << cards[i][c+1] << "\n";
      }
    }
  }

  cout << std::flush;
  return 0;
}
