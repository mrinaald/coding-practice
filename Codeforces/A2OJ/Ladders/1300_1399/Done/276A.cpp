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

  int n, k;
  cin >> n >> k;

  int f, t, i, x;

  cin >> f >> t;
  int max_joy;
  if (t >= k) {
    max_joy = f - (t - k);
  } else {
    max_joy = f;
  }

  for (i=1; i<n; ++i) {
    cin >> f >> t;

    if (t >= k) {
      x = f - (t - k);
    } else {
      x = f;
    }

    if (x > max_joy) {
      max_joy = x;
    }
  }

  cout << max_joy << "\n";
  cout << std::flush;
  return 0;
}
