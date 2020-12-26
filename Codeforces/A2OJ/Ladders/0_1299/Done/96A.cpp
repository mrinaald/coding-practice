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

  size_t pos = str.find("0000000");
  if (pos == string::npos) {
    pos = str.find("1111111");
  }

  if (pos == string::npos) {
    cout << "NO\n";
  }
  else {
    cout << "YES\n";
  }

  cout << std::flush;
  return 0;
}
