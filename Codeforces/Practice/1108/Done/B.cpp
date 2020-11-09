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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, i;
  cin >> n;

  vector<int> divisors(n);
  for (i=0; i<n; ++i) {
    cin >> divisors[i];
  }

  sort(rall(divisors));

  int x = divisors[0];
  int y = -1;

  for (i=1; i<n; ++i) {
    if (divisors[i] == divisors[i-1]) {
      y = divisors[i];
      break;
    }
    if ((x % divisors[i]) != 0) {
      y = divisors[i];
      break;
    }
  }

  cout << x << " " << y << endl;

  return 0;
}
