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

#define GRID_SIZE 3

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool grid[GRID_SIZE][GRID_SIZE];
  int s;
  int i, j;

  // initializing grid
  for (i=0; i<GRID_SIZE; ++i) {
    for (j=0; j<GRID_SIZE; ++j) {
      grid[i][j] = true;
    }
  }

  // handing switch toggles
  for (i=0; i<GRID_SIZE; ++i) {
    for (j=0; j<GRID_SIZE; ++j) {
      cin >> s;

      if ((s & 1) == 0)
        continue;   // if even, continue

      grid[i][j] = !grid[i][j];

      if (i+1 < GRID_SIZE)
        grid[i+1][j] = !grid[i+1][j];

      if (j+1 < GRID_SIZE)
        grid[i][j+1] = !grid[i][j+1];

      if (i-1 >= 0)
        grid[i-1][j] = !grid[i-1][j];

      if (j-1 >= 0)
        grid[i][j-1] = !grid[i][j-1];
    }
  }

  // Printing final grid
  for (i=0; i<GRID_SIZE; ++i) {
    for (j=0; j<GRID_SIZE; ++j) {
      if (grid[i][j]) {
        cout << 1;
      }
      else {
        cout << 0;
      }
    }
    cout << "\n";
  }


  cout << std::flush;
  return 0;
}
