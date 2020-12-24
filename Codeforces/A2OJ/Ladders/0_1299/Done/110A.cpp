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

  string num;
  cin >> num;

  int len = num.length();
  int i;
  ullong lucky_count = 0;
  for (i=0; i<len; ++i) {
    if ((num[i] == '4') || (num[i] == '7'))
      ++lucky_count;
  }

  string lucky_count_str = to_string(lucky_count);
  len = lucky_count_str.length();
  bool is_nearly_lucky = true;
  for (i=0; i<len; ++i) {
    if ((lucky_count_str[i] != '4') && (lucky_count_str[i] != '7')) {
      is_nearly_lucky = false;
      break;
    }
  }

  if (is_nearly_lucky) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }

  cout << std::flush;
  return 0;
}
