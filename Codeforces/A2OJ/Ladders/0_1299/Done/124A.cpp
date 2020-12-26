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

  int n, A, B;
  cin >> n >> A >> B;

  int a = A;
  int b = B;

  while((b >= 0) && (a+b >= n)) {
    b--;
  }
  if (b < 0) {
    cout << -1 << endl;
    return 0;
  }

  while ((a < n) && (a+b < n-2)) {
    a++;
  }
  if (a == n) {
    cout << -1 << endl;
    return 0;
  }

  cout << min(n - a, b + 1) << endl;

  cout << std::flush;
  return 0;
}
