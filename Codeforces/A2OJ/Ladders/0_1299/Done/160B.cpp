#include <iostream>
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

  int n;
  cin >> n;

  string str;
  cin >> str;

  sort(str.begin(), str.begin() + n);
  sort(str.begin() + n, str.begin() + (2 * n));

  if (str[0] < str[n]) {
    int i;
    for (i=1; i<n; ++i) {
      if (str[i] >= str[i + n])
        break;
    }

    if (i == n) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  else if (str[0] > str[n]) {
    int i;
    for (i=1; i<n; ++i) {
      if (str[i] <= str[i + n])
        break;
    }

    if (i == n) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  else {
    cout << "NO\n";
  }

  cout << std::flush;
  return 0;
}
