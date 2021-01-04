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

#define ROWS 5
#define COLS 5
#define MID_ROW 3
#define MID_COL 3

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  int i, j;
  int x;

  for (i=1; i<=ROWS; ++i) {
    for (j=1; j<=COLS; ++j) {
      cin >> x;
      if (x == 1) {
        r = i;
        c = j;
      }
    }
  }

  x = abs(r - MID_ROW) + abs(c - MID_COL);
  cout << x << "\n";

  cout << std::flush;
  return 0;
}
