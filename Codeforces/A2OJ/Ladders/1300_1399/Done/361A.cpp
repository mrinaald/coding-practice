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

  int n, k;
  cin >> n >> k;

  vector<vector<int>> table(n, vector<int>(n, 0));
  int i, j;

  for (i=0; i<n; ++i) {
    table[i][i] = k;
  }

  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) {
      cout << table[i][j] << " ";
    }
    cout << "\n";
  }

  cout << std::flush;
  return 0;
}
