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

  int n, x, y, z;
  int X, Y, Z;

  X = Y = Z = 0;
  cin >> n;
  while (n--) {
    cin >> x >> y >> z;
    X += x;
    Y += y;
    Z += z;
  }

  if ((X == 0) && (Y == 0) && (Z == 0))
    cout << "YES\n";
  else
    cout << "NO\n";

  cout << std::flush;
  return 0;
}
