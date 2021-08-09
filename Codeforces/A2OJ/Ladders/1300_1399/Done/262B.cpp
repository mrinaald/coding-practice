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

long total_income(const vector<int>& arr) {
  long total = 0;
  for (int i=0; i<arr.size(); ++i) {
    total += arr[i];
  }
  return total;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n, 0);
  int neg_index = 0;
  int i;
  for (i=0; i<n; ++i) {
    cin >> arr[i];
    if (arr[i] <= 0) {
      neg_index = i;
    }
  }

  i = 0;
  while (i <= neg_index && k > 0) {
    arr[i] *= -1;
    --k;
    ++i;
  }

  if (k & 1) {
    if ((i > 0) && (arr[i-1] < arr[i])) {
      arr[i-1] *= -1;
        }
    else {
      arr[i] *= -1;
    }
  }

  cout << total_income(arr) << "\n";

  cout << std::flush;
  return 0;
}
