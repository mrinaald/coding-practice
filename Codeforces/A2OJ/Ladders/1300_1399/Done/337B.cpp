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

int gcd(int a, int b) {
  if (a == 1 || b == 1) {
    return 1;
  }
  if (a < b) {
    return gcd(b, a);
  }
  if (b == a || b == 0) {
    return a;
  }
  return gcd(b, a%b);
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int bc = b * c;
  int ad = a * d;
  int g = gcd(bc, ad);
  int p, q;
  if (bc >= ad) {
    p = ad / g;
    q = bc / g;
  } else {
    p = bc / g;
    q = ad / g;
  }
  cout << (q-p) << "/" << q << "\n";

  cout << std::flush;
  return 0;
}
