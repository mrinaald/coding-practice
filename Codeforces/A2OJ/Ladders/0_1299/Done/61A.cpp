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

  string n1, n2;
  cin >> n1;
  cin >> n2;

  string ans = n1;
  int len = n1.length();

  for (int i=0; i<len; ++i) {
    if (n1[i] != n2[i])
      ans[i] = '1';
    else
      ans[i] = '0';
  }

  cout << ans << "\n";
  cout << std::flush;
  return 0;
}
