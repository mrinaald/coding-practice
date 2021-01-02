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

  int n;
  cin >> n;

  int i, x, y;
  int u_odd = 0;
  int l_odd = 0;
  int u_odd_l_even = 0;
  int l_odd_u_even = 0;
  for (i=0; i<n; ++i) {
    cin >> x >> y;

    if (x & 1) {
      ++u_odd;
      if ((y & 1) == 0)
        ++u_odd_l_even;
    }

    if (y & 1) {
      ++l_odd;
      if ((x & 1) == 0)
        ++l_odd_u_even;
    }
  }

  if (((u_odd & 1) == 0) && ((l_odd & 1) == 0)) {
    cout << "0\n";
  }
  else if (((u_odd & 1) == 0) || ((l_odd & 1) == 0)) {
    cout << "-1\n";
  }
  else if ((l_odd_u_even > 0) || (u_odd_l_even > 0)) {
    cout << "1\n";
  }
  else {
    cout << "-1\n";
  }

  cout << std::flush;
  return 0;
}
