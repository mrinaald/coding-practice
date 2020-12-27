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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s1, s2;
  std::getline(cin, s1);
  std::getline(cin, s2);

  int len1 = s1.length();
  int len2 = s2.length();

  int i;
  vector<int> headline_count(52, 0);
  for (i=0; i<len1; ++i) {
    if (s1[i] == ' ')
      continue;
    if (s1[i] <= 'Z')
      headline_count[s1[i] - 'A']++;
    else if (s1[i] >= 'a')
      headline_count[s1[i] - 'a' + 26]++;
  }

  vector<int> message_count(52, 0);
  for (i=0; i<len2; ++i) {
    if (s2[i] == ' ')
      continue;
    if (s2[i] <= 'Z')
      message_count[s2[i] - 'A']++;
    else if (s2[i] >= 'a')
      message_count[s2[i] - 'a' + 26]++;
  }

  for (i=0; i<52; ++i) {
    if (message_count[i] > headline_count[i])
      break;
  }

  cout << ((i == 52) ? "YES\n" : "NO\n");
  cout << std::flush;
  return 0;
}
