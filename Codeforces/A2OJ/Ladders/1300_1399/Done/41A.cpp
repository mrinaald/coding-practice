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

  string s, t;
  cin >> s;
  cin >> t;

  if (s.length() != t.length()) {
    cout << "NO" << endl;
    return 0;
  }

  int len = s.length();
  int i, j;
  i = 0;
  j = len - 1;
  while (i < len) {
    if (s[i] != t[j])
      break;
    ++i;
    --j;
  }

  if (i == len) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }

  cout << std::flush;
  return 0;
}
