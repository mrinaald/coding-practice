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

  ullong n;
  cin >> n;

  short num;
  ullong count5 = 0;
  ullong count0 = 0;
  ullong i;
  for (i=0; i<n; ++i) {
    cin >> num;
    switch(num) {
    case 0: ++count0; break;
    case 5: ++count5; break;
    }
  }

  ullong q = count5 / 9;

  if (q == 0) {
    if (count0 > 0) {
      cout << "0" << endl;
    }
    else {
      cout << "-1" << endl;
    }
    return 0;
  }

  // q > 0
  if (count0 < 1) {
    cout << "-1" << endl;
    return 0;
  }

  ullong lim = q * 9;
  string ans = "";
  for (i=0; i<lim; ++i) {
    ans += "5";
  }
  for (i=0; i<count0; ++i) {
    ans += "0";
  }

  cout << ans << "\n";
  cout << std::flush;
  return 0;
}
