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

  int n;
  cin >> n;

  vector<llong> stairs(n, 0);
  int i;
  for (i=0; i<n; ++i) {
    cin >> stairs[i];
  }

  int m;
  cin >> m;

  vector<llong> boxes(m, 0);
  llong w, h;
  llong x;

  for (i=0; i<m; ++i) {
    cin >> w >> h;

    x = max(stairs[0], stairs[w-1]);
    boxes[i] = x;
    stairs[0] = stairs[w-1] = x + h;
  }

  for (i=0; i<m; ++i) {
    cout << boxes[i] << "\n";
  }

  cout << std::flush;
  return 0;
}
