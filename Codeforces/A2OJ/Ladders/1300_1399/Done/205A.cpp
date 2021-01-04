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

  int t, min_t, min_id;
  cin >> t;
  min_t = t;
  min_id = 0;

  for (int i=1; i<n; ++i) {
    cin >> t;
    if (t < min_t) {
      min_t = t;
      min_id = i;
    }
    else if (t == min_t) {
      min_id = -1;
    }
  }

  if (min_id == -1) {
    cout << "Still Rozdil\n";
  }
  else {
    cout << min_id + 1 << "\n";
  }
  cout << std::flush;
  return 0;
}
