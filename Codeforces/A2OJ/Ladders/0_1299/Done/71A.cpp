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

#define MAX_LEN 10

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string word;
  while (n--) {
    cin >> word;

    if (word.length() <= MAX_LEN) {
      cout << word << "\n";
      continue;
    }

    cout << word[0] << word.length() - 2 << word[word.length() - 1] << "\n";
  }

  cout << std::flush;
  return 0;
}
