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

  string str;
  cin >> str;

  string hello = "hello";
  size_t pos = -1;
  int i;

  for (i=0; i<hello.length(); ++i) {
    pos = str.find(hello[i], pos + 1);
    if (pos == string::npos)
      break;
  }

  if (i == hello.length()) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }

  cout << std::flush;
  return 0;
}
