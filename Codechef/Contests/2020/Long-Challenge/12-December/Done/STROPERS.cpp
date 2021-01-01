#include <iostream>
#include <set>
#include <tuple>

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

  int t;
  cin >> t;

  string str;
  int i, j;
  int len, slen;
  int even_count, odd_count, count;
  set<tuple<int, int, int>> eq_set;
  while (t--) {
    cin >> str;

    len = str.length();
    if (!eq_set.empty())
      eq_set.clear();

    for (i=0; i<len; ++i) {
      count = even_count = odd_count = 0;

      for (j=i; j<len; ++j) {
        if (str[j] == '1') {
          ++count;
        }
        else {
          if (count & 1) {
            ++odd_count;
          }
          else {
            ++even_count;
          }
        }

        eq_set.insert({j-i+1, odd_count, even_count});
      }
    }

    cout << eq_set.size() << "\n";
  }

  cout << std::flush;
  return 0;
}
