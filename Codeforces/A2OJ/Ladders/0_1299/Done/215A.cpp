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
  int i, j;

  cin >> n;
  vector<int> a(n, 0);
  for (i=0; i<n; ++i)
    cin >> a[i];

  cin >> m;
  vector<int> b(m, 0);
  for (i=0; i<m; ++i)
    cin >> b[i];

  int max_ratio = -1;
  int count = 0;
  int r;

  for (j=0; j<m; ++j) {
    for (i=0; i<n; ++i) {
      if (a[i] > b[j])
        break;
      if ((b[j] % a[i]) != 0)
        continue;

      r = b[j] / a[i];
      if (r > max_ratio) {
        max_ratio = r;
        count = 1;
      }
      else if (r == max_ratio) {
        count++;
      }
    }
  }

  cout << count << "\n";

  cout << std::flush;
  return 0;
}
