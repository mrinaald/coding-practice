#include <iostream>
#include <vector>
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

#define MAX_CHARS 26

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  string cards;
  cin >> cards;

  vector<int> char_count(MAX_CHARS, 0);
  int i;
  for (i=0; i<n; ++i) {
    char_count[cards[i] - 'A']++;
  }

  sort(rall(char_count));

  int kk;
  llong c;
  llong coins = 0;
  for (i=0; i<MAX_CHARS; ++i) {
    if (k <= 0)
      break;

    kk = min(k, char_count[i]);
    c = kk;
    c *= c;
    coins += c;
    k -= kk;
  }

  cout << coins << "\n";
  cout << std::flush;
  return 0;
}
