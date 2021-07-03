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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int n_sum = ((n * (n+1)) / 2);
  m = m % n_sum;

  for (int i=1; i<=n; ++i) {
    if (i <= m) {
      m -= i;
    } else {
      break;
    }
    if (m == 0) {
      break;
    }
  }

  cout << m << "\n";
  cout << std::flush;
  return 0;
}
