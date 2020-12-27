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

#define MAX_A 1000

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> count(MAX_A+1, 0);
  int i, a;
  int max_count = 0;
  for (i=0; i<n; ++i) {
    cin >> a;
    count[a]++;
    if (count[a] > max_count)
      max_count = count[a];
  }

  int half = (n/2) + (n & 1);
  if (max_count <= half)
    cout << "YES\n";
  else
    cout << "NO\n";

  cout << std::flush;
  return 0;
}
