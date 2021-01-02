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

  int i, c;
  int count_25 = 0;
  int count_50 = 0;
  int count_100 = 0;

  for (i=0; i<n; ++i) {
    cin >> c;

    if (c == 25) {
      ++count_25;
    }
    else if (c == 50) {
      if (count_25 > 0) {
        --count_25;
        ++count_50;
      }
      else
        break;
    }
    else if (c == 100) {
      if (count_25 > 0 && count_50 > 0) {
        --count_25;
        --count_50;
        ++count_100;
      }
      else if (count_25 >= 3) {
        count_25 -= 3;
        ++count_100;
      }
      else
        break;
    }
  }

  if (i == n)
    cout << "YES\n";
  else
    cout << "NO\n";

  cout << std::flush;
  return 0;
}
