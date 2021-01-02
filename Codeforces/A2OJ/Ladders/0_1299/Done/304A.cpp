#include <iostream>
#include <cmath>

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

  int a, a2, b, c;
  int count = 0;

  for (c=n; c>1; --c) {
    for (b=c-1; b>1; --b) {
      a2 = (c*c) - b*b;
      a = sqrt(a2);
      if (a > b)
        break;
      if ((a*a) == a2)
        count++;
    }
  }

  cout << count << endl;
  cout << std::flush;
  return 0;
}
