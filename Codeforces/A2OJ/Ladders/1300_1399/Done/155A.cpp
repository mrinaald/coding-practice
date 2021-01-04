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

  int n;
  cin >> n;

  int amazing_count = 0;

  int s;
  cin >> s;
  int min_score = s;
  int max_score = s;

  for (int i=1; i<n; ++i) {
    cin >> s;
    if (s < min_score) {
      min_score = s;
      ++amazing_count;
    }
    if (s > max_score) {
      max_score = s;
      ++amazing_count;
    }
  }

  cout << amazing_count << "\n";

  cout << std::flush;
  return 0;
}
