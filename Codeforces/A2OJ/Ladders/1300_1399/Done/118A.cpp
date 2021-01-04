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

char to_lower(const char ch) {
  if (('A' <= ch) && (ch <= 'Z'))
    return ch - 'A' + 'a';
  else
    return ch;
}

bool is_vowel(const char ch) {
  switch(ch) {
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
  case 'Y':
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':
  case 'y':
    return true;
  default:
    return false;
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  cin >> str;

  string ans = "";
  int len = str.length();
  for (int i=0; i<len; ++i) {
    if (is_vowel(str[i]))
      continue;
    ans.append(".");
    ans += to_lower(str[i]);
  }

  cout << ans << endl;
  cout << std::flush;
  return 0;
}
