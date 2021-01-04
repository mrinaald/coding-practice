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

  vector<string> board(n);
  int r, c;
  for (r=0; r<n; ++r)
    cin >> board[r];

  string piece = "BW";

  for (r=0; r<n; ++r) {
    for (c=0; c<m; ++c) {
      if (board[r][c] == '-')
        continue;
      if ((r + c) & 1) {
        board[r][c] = piece[1];
      }
      else {
        board[r][c] = piece[0];
      }
    }

    cout << board[r] << "\n";
  }

  cout << std::flush;
  return 0;
}
