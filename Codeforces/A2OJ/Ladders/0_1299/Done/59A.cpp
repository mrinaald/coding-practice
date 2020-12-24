#include <iostream>
#include <cctype>

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

  string str;
  cin >> str;

  int len = str.length();
  int i;
  int upper = 0;

  for (i=0; i<len; ++i) {
    if (isupper(str[i])) {
      ++upper;
    }
  }

  int lower = len - upper;

  if (lower >= upper) {
    for (i=0; i<len; ++i)
      cout << ((char) tolower(str[i]));
  }
  else {
    for (i=0; i<len; ++i)
      cout << ((char) toupper(str[i]));
  }

  cout << "\n";
  cout << std::flush;
  return 0;
}
