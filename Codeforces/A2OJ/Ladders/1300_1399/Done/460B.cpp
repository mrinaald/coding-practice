#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MAX_X 1000000000LL

llong digit_sum(llong num) {
  int dig;
  int sum = 0;
  while (num > 0) {
    dig = num % 10;
    sum += dig;
    num /= 10;
  }
  return sum;
}

llong pow(llong s, int y) {
  if (y == 0) {
    return 1LL;
  }
  if (y == 1) {
    return s;
  }

  llong ans = pow(s, y/2);
  ans *= ans;
  if (y & 1) {
    ans *= s;
  }
  return ans;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b ,c;
  cin >> a >> b >> c;

  vector<llong> arr;
  llong sum, x;
  for (llong s=1; s<=81; ++s) {
    x = pow(s, a);
    x *= b;
    x += c;
    sum = digit_sum(x);

    if (sum == s && x > 0 && x < MAX_X) {
      arr.pb(x);
    }
  }

  cout << arr.size() << "\n";
  for (int i=0; i<arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << "\n";

  cout << std::flush;
  return 0;
}
