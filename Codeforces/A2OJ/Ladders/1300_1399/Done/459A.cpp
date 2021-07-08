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

#define limit 1000

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int dist;
  if (x1 == x2) {
    dist = abs(y1 - y2);
    if ((x1 + dist) <= limit) {
      cout << x1 + dist << " " << y1 << " "
           << x2 + dist << " " << y2 << "\n";
    } else if ((x1 - dist) >= -limit){
      cout << x1 - dist << " " << y1 << " "
           << x2 - dist << " " << y2 << "\n";
    } else {
      cout << -1 << "\n";
    }
  } else if (y1 == y2) {
    dist = abs(x1 - x2);
    if ((y1 + dist) <= limit) {
      cout << x1 << " " << y1 + dist << " "
           << x2 << " " << y2 + dist << "\n";
    } else if ((y1 - dist) >= -limit) {
      cout << x1 << " " << y1 - dist << " "
           << x2 << " " << y2 - dist << "\n";
    } else {
      cout << -1 << "\n";
    }
  } else if ( (y2 - y1 == x2 - x1) || (y2 - y1 == x1 - x2) ) {
    cout << x1 << " " << y2 << " "
         << x2 << " " << y1 << "\n";
  } else {
    cout << -1 << "\n";
  }

  cout << std::flush;
  return 0;
}
