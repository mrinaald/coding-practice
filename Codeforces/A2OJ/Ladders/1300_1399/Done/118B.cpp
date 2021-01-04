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

  int n;
  cin >> n;

  int lim = (2 * n);
  vector<vector<char>> pattern(lim + 1, vector<char>(lim + 1, '\0'));

  int row;
  int l, r;
  int x;

  for (row=0; row<=lim; ++row) {
    l = abs(n - row);
    r = n + row;
    if (r > lim)
      r = lim + n - row;

    for (x=0; x<l; ++x)
      pattern[row][x] = ' ';

    x = 0;
    while (l <= r) {
      pattern[row][l] = x + '0';
      pattern[row][r] = x + '0';
      ++l;
      --r;
      ++x;
    }
  }

  for (row=0; row<=lim; ++row) {
    for (x=0; x<lim; ++x) {
      if (pattern[row][x+1] == '\0') {
        cout << pattern[row][x];
        break;
      }
      else {
        cout << pattern[row][x] << " ";
      }
    }
    if (pattern[row][lim] == '\0')
      cout << "\n";
    else
      cout << pattern[row][lim] << "\n";
  }

  cout << std::flush;
  return 0;
}
