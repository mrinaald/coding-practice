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

#define M 1000000007

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  llong x, y, n;
  cin >> x >> y >> n;

  llong fn;

  switch(n % 6) {
  case 0:
    fn = (-y + x) % M;
    break;

  case 1:
    fn = x % M;
    break;

  case 2:
    fn = y % M;
    break;

  case 3:
    fn = (y - x) % M;
    break;

  case 4:
    fn = (-x) % M;
    break;

  case 5:
    fn = (-y) % M;
    break;
  }

  if (fn < 0)
    fn += M;

  cout << fn << "\n";
  cout << std::flush;
  return 0;
}
