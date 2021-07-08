/* Problem solved very poorly. A better strategy exists. Look at
 * https://codeforces.com/contest/121/submission/18817251
 */
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

bool is_lucky_number(int n) {
  if (n <= 0)
    return false;

  bool is_lucky = true;
  int dig;
  while (n > 0) {
    dig = n % 10;
    n /= 10;
    if (dig != 4 && dig != 7) {
      is_lucky = false;
      break;
    }
  }
  return is_lucky;
}

ullong next_lucky_number(ullong n) {
  if (n <= 0)
    return 4;
  if (is_lucky_number(n))
    return n;

  ullong div = 1;
  ullong max_div = 1;
  ullong mod = 10;
  ullong max_mod = 10;
  ullong dig;
  while (div <= n) {
    dig = ((n % mod) / div);
    if (dig != 4 && dig != 7) {
      max_div = div;
      max_mod = mod;
    }
    mod *= 10;
    div *= 10;
  }

  dig = (n % max_mod) / max_div;
  div = max_div;
  mod = max_mod;
  if (dig < 4) {
    // dig \in {0, 1, 2, 3}
    // change this `dig` position to 4, and make everything to the right as 4
    n = (n / max_mod) * max_mod;
  } else if (dig < 7) {
    // dig \in {5, 6}
    // change this `dig` position to 7, and make everything to the right as 4
    n = (n / max_mod) * max_mod;
    n += (7 * div);
    div /= 10;
  } else {
    // dig \in {8, 9}
    div *= 10;
    mod *= 10;
    dig = (n % mod) / div;
    while (dig >= 7) {
      div *= 10;
      mod *= 10;
      dig = (n % mod) / div;
    }
    n = (n / mod) * mod;
    if (dig < 4) {
      n += (4 * div);
    } else if (dig < 7) {
      n += (7 * div);
    }
    div /= 10;
  }

  while (div > 0) {
    n += (4 * div);
    div /= 10;
  }
  return n;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int l, r;
  cin >> l >> r;

  ullong sum = 0;
  ullong i = l;
  ullong n;
  while (i <= r) {
    n = next_lucky_number(i);
    if (n > r) {
      sum += ((r - i + 1ULL) * n);
    } else {
      sum += ((n - i + 1ULL) * n);
    }
    i = n + 1;
  }

  cout << sum << "\n";

  cout << std::flush;
  return 0;
}
