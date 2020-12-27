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

  string g1;
  cin >> g1;

  string g2;
  cin >> g2;

  int len1 = g1.length();
  int len2 = g2.length();

  if (len1 != len2) {
    cout << "NO" << endl;
    return 0;
  }

  char ch1, ch2;
  int id1, id2;
  int diff_count = 0;
  int i;

  for (i=0; i<len1; ++i) {
    if (g1[i] == g2[i])
      continue;

    diff_count++;
    switch(diff_count) {
    case 1:
      ch1 = g1[i]; id1 = i; break;
    case 2:
      ch2 = g1[i]; id2 = i; break;
    default:
      i = len1;
    }
  }

  if (diff_count == 0) {
    cout << "YES\n";
  }
  else if (diff_count == 2) {
    if (ch1 == g2[id2] && ch2 == g2[id1])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  else {
    cout << "NO\n";
  }

  cout << std::flush;
  return 0;
}
