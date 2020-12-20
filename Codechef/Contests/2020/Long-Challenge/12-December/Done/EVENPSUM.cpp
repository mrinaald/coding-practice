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

  int t;
  cin >> t;

  ullong A, B;
  ullong Ao, Ae, Bo, Be;

  while (t--) {
    cin >> A >> B;

    Ae = A / 2;
    Be = B / 2;
    Ao = Ae + (A & 1);
    Bo = Be + (B & 1);

    A = (Ae * Be) + (Ao * Bo);
    cout << A << "\n";
  }

  cout << std::flush;
  return 0;
}
