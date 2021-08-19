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

#define IMPOSSIBLE cout << "Impossible" << endl

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b, c;
  cin >> a >> b >> c;

  int e12 = (a + b - c);
  int e13 = (a + c - b);
  int e23 = (b + c - a);
  if (
         (e12 < 0) || (e12 & 1)
      || (e13 < 0) || (e13 & 1)
      || (e23 < 0) || (e23 & 1)) {
    IMPOSSIBLE;
    return 0;
  }

  if (
      ((e12 == 0) && (e13 == 0)) || ((e13 == 0) && (e23 == 0)) || ((e12 == 0) && (e23 == 0))
      ) {
    IMPOSSIBLE;
    return 0;
  }

  e12 /= 2;
  e13 /= 2;
  e23 /= 2;

  cout << e12 << " " << e23 << " " << e13 << "\n";

  cout << std::flush;
  return 0;
}
