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

  string t;
  cin >> t;
  if (n == 1) {
    cout << t << endl;
    return 0;
  }

  string t1, t2;
  int c1 = 0;
  int c2 = 0;

  t1 = t;
  c1 = 1;
  t2 = "";

  n--;
  while (n--) {
    cin >> t;
    if (t == t1)
      c1++;
    else {
      if (t2 == "")
        t2 = t;
      c2++;
    }
  }

  if (c1 > c2)
    cout << t1 << "\n";
  else
    cout << t2 << "\n";

  cout << std::flush;
  return 0;
}
