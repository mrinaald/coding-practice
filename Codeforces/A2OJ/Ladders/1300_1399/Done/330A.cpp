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

  int r, c;
  cin >> r >> c;

  string row;
  vector<bool> evil_rows(r, false);
  vector<bool> evil_cols(c, false);
  int row_cnt = 0;
  int col_cnt = 0;
  int i;
  size_t pos;
  for (i=0; i<r; ++i) {
    cin >> row;
    pos = row.find('S');
    if (pos != string::npos) {
      if (evil_rows[i] == false) {
        evil_rows[i] = true;
        row_cnt++;
      }

      while (pos != string::npos) {
        if (evil_cols[pos] == false) {
          evil_cols[pos] = true;
          col_cnt++;
        }

        pos = row.find('S', pos+1);
      }
    }
  }

  int ans = ((r - row_cnt) * c) + ((c - col_cnt) * row_cnt);
  cout << ans << "\n";

  cout << std::flush;
  return 0;
}
