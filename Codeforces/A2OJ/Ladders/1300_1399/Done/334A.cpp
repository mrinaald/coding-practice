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

  vector<vector<int>> arr(n, vector<int>(n, 0));
  int i, j;

  int k = 1;
  int n2 = n * n;
  i = j = 0;
  while (k <= n2) {
    arr[i][j] = k;

    if (k % n == 0) {
      j++;
    } else {
      i = (i + 1) % n;
    }
    ++k;
  }

  for (i=0; i<n; ++i) {
    for (j=0; j<n; ++j) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
  cout << std::flush;
  return 0;
}
