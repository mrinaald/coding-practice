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

#define YES "YES\n"
#define NO "NO\n"

ullong reverse_number_special(ullong n, ullong ignore_int) {
  ullong res = 0;
  ullong r;

  while (n > 0) {
    r = n % 10;
    n /= 10;

    if (r == ignore_int) {
      continue;
    }
    res = (10 * res) + r;
  }

  return res;
}

ullong remove_zeros(ullong n) {
  ullong x = reverse_number_special(n, 0);
  return reverse_number_special(x, 0);
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ullong a, b, c;
  cin >> a >> b;
  c = a + b;

  a = remove_zeros(a);
  b = remove_zeros(b);
  c = remove_zeros(c);

  if ((a + b) == c) {
    cout << YES;
  } else {
    cout << NO;
  }

  cout << std::flush;
  return 0;
}
