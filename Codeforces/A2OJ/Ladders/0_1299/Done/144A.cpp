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

  int h;
  int min_h = 200;
  int max_h = -1;
  int min_h_id = -1;
  int max_h_id = -1;
  for (int i=0; i<n; ++i) {
    cin >> h;

    if (h > max_h) {
      max_h = h;
      max_h_id = i;
    }
    if (h <= min_h) {
      min_h = h;
      min_h_id = i;
    }
  }

  if (max_h_id < min_h_id) {
    cout << max_h_id + (n - 1 - min_h_id) << "\n";
  } else {
    cout << max_h_id + (n - 1 - min_h_id) - 1<< "\n";
  }

  cout << std::flush;
  return 0;
}
