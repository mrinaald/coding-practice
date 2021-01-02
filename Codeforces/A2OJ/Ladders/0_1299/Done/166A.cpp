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

bool my_comparator(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
  if (lhs.first > rhs.first) {
    return true;
  }
  else if (lhs.first < rhs.first) {
    return false;
  }
  else {
    return lhs.second < rhs.second;
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<std::pair<int, int>> arr(n);
  int i, p, t;
  for (i=0; i<n; ++i) {
    cin >> p >> t;
    arr[i] = mp(p, t);
  }

  sort(all(arr), my_comparator);

  std::pair<int, int> *kth_team = &(arr[k-1]);
  int count = 1;

  for (i=k-2; i>=0; --i) {
    if ((kth_team->first == arr[i].first) && (kth_team->second == arr[i].second))
      ++count;
    else
      break;
  }

  for (i=k; i<n; ++i) {
    if ((kth_team->first == arr[i].first) && (kth_team->second == arr[i].second))
      ++count;
    else
      break;
  }

  cout << count << "\n";
  cout << std::flush;
  return 0;
}
