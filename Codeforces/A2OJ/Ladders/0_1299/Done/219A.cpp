#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MAX_CHARS 26

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k;
  cin >> k;

  string str;
  cin >> str;

  if (k == 1) {
    cout << str << endl;
    return 0;
  }

  if (str.length() % k != 0) {
    cout << -1 << endl;
    return 0;
  }

  int len = str.length();
  vector<int> arr(MAX_CHARS, 0);
  int i, q;
  for (i=0; i<len; ++i) {
    arr[str[i] - 'a']++;
  }

  str = "";
  while (str.length() != len) {
    for (i=0; i<MAX_CHARS; ++i) {
      if (arr[i] <= 0)
        continue;
      if (arr[i] % k != 0) {
        str.clear();
        break;
      }

      q = arr[i] / k;
      str.append(q, 'a' + i);
    }

    if (str.empty())
      break;
  }

  if (str.empty()) {
    cout << -1 << endl;
  }
  else {
    cout << str << endl;
  }

  cout << std::flush;
  return 0;
}
