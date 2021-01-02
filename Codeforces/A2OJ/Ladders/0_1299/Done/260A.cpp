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

  int a, b, n;
  cin >> a >> b >> n;

  int x;
  int i;
  for (i=0; i<10; ++i) {
    x = (a * 10) + i;
    if (x % b == 0)
      break;
  }

  if (i == 10) {
    cout << -1 << endl;
    return 0;
  }

  cout << x;
  for (i=1; i<n; ++i)
    cout << 0;
  cout << "\n";

  cout << std::flush;
  return 0;
}
