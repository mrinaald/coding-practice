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


ullong reduce_to_one_digit(ullong num) {
  ullong sum = 0;
  int dig;

  while (num > 0) {
    dig = num % 10;
    num /= 10;
    sum += dig;
  }

  if (sum < 10) {
    return 1;
  } else {
    return 1ULL + reduce_to_one_digit(sum);
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string n;
  cin >> n;

  if (n.length() == 1) {
    cout << 0 << endl;
    return 0;
  }

  int i;
  ullong sum = 0;
  for (i=0; i<n.length(); ++i) {
    sum += (n[i] - '0');
  }

  if (sum < 10) {
    cout << 1 << endl;
    return 0;
  }

  ullong steps = 1 + reduce_to_one_digit(sum);
  cout << steps << endl;

  cout << std::flush;
  return 0;
}
