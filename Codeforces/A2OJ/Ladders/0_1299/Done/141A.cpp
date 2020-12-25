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

  string name1, name2, letters;
  vector<int> char_count1(26, 0);
  vector<int> char_count2(26, 0);

  cin >> name1;
  cin >> name2;
  cin >> letters;

  if ((name1.length() + name2.length()) != letters.length()) {
    cout << "NO" << endl;
    return 0;
  }

  int i;
  int len = name1.length();
  for (i=0; i<len; ++i) {
    char_count1[name1[i] - 'A']++;
  }

  len = name2.length();
  for (i=0; i<len; ++i) {
    char_count1[name2[i] - 'A']++;
  }

  len = letters.length();
  for (i=0; i<len; ++i) {
    char_count2[letters[i] - 'A']++;
  }

  bool is_possible = true;
  for (i=0; i<26; ++i) {
    if (char_count1[i] != char_count2[i]) {
      is_possible = false;
      break;
    }
  }

  if (is_possible) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }

  cout << std::flush;
  return 0;
}
