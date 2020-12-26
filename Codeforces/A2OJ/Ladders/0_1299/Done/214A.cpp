#include <iostream>
#include <cmath>

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

  int a, b;
  int a2, b2;
  int lim_a = max((int) sqrt(n), m);
  int lim_b = max((int) sqrt(m), n);

  int ans = 0;
  for (a=0; a<=lim_a; ++a) {
    if (a > m)
      break;

    a2 = a * a;
    if (a2 > n)
      break;

    for (b=0; b<=lim_b; ++b) {
      if (b > n)
        break;

      b2 = b * b;
      if (b2 > m)
        break;

      if ((a2 + b == n) && (a + b2 == m))
        ans++;
    }
  }

  cout << ans << endl;
  cout << std::flush;
  return 0;
}
