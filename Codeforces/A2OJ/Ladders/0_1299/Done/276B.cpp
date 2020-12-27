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

#define FIRST "First\n"
#define SECOND "Second\n"
#define MAX_CHARS 26

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  cin >> str;

  int len = str.length();
  vector<int> char_count(MAX_CHARS, 0);
  int i;
  for (i=0; i<len; ++i) {
    char_count[str[i] - 'a']++;
  }

  int even_count = 0;
  int odd_count = 0;
  for (i=0; i<MAX_CHARS; ++i) {
    if (char_count[i] == 0)
      continue;
    if (char_count[i] & 1)
      ++odd_count;
    else
      ++even_count;
  }

  if (len & 1) {
    cout << FIRST;
  }
  else {
    if (odd_count > 0)
      cout << SECOND;
    else
      cout << FIRST;
  }

  cout << std::flush;
  return 0;
}
