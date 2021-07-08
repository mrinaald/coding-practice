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

#define YES "Happy Alex\n"
#define NO "Poor Alex\n"

struct Laptop {
  int price = -1;
  int quality = -1;
};

bool laptop_comparator(const Laptop& lhs, const Laptop& rhs) {
  if (lhs.price < rhs.price)
    return true;
  else
    return false;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int i;
  vector<Laptop> arr(n);
  for (i=0; i<n; ++i) {
    cin >> arr[i].price >> arr[i].quality;
  }

  if (n == 1) {
    cout << NO;
    cout << std::flush;
    return 0;
  }

  sort(all(arr), laptop_comparator);

  // Alex will be wrong only if Quality is also increasing from left to right.
  for (i=1; i<n; ++i) {
    if (arr[i].quality < arr[i-1].quality) {
      break;
    }
  }

  if (i < n) {
    cout << YES;
  } else {
    cout << NO;
  }

  cout << std::flush;
  return 0;
}
