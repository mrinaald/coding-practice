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

bool is_prime(const int p) {
  if (((p & 1) == 0) && (p != 2))
    return false;

  int x;
  int lim = p / 2;
  for (x=3; x <= lim; x+=2) {
    if (p % x == 0)
      return false;
  }

  return true;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  int x;
  bool found_prime = false;
  for (x=n+1; x<=m; ++x) {
    if (is_prime(x)) {
      found_prime = true;
      break;
    }
  }

  if (found_prime && (x == m))
    cout << "YES\n";
  else
    cout << "NO\n";

  cout << std::flush;
  return 0;
}
