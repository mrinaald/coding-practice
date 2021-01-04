#include <iostream>
#include <cctype>
#include <algorithm>

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

  string str1, str2;
  cin >> str1;
  cin >> str2;

  if (str1.length() < str2.length()) {
    cout << -1 << endl;
    return 0;
  }
  else if (str1.length() > str2.length()) {
    cout << 1 << endl;
    return 0;
  }

  transform(all(str1), str1.begin(), ::tolower);
  transform(all(str2), str2.begin(), ::tolower);

  if (str1 == str2) {
    cout << "0\n";
  }
  else if (str1 < str2) {
    cout << "-1\n";
  }
  else {
    cout << "1\n";
  }

  cout << std::flush;
  return 0;
}
