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

ullong get_nC2(const ullong n) {
  if (n <= 1) {
    return 0;
  }
  else if (n & 1) {
    return ((n-1) / 2 ) * n;
  }
  else {
    return (n / 2) * (n - 1);
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int flower;
  int i;

  cin >> flower;
  int max_flower = flower;
  ullong max_count = 1;
  int min_flower = flower;
  ullong min_count = 1;
  for (i=1; i<n; ++i) {
    cin >> flower;
    if (flower > max_flower) {
      max_flower = flower;
      max_count = 1;
    }
    else if (flower == max_flower) {
      ++max_count;
    }

    if (flower < min_flower) {
      min_flower = flower;
      min_count = 1;
    }
    else if (flower == min_flower) {
      ++min_count;
    }
  }

  cout << max_flower - min_flower << " ";
  if (max_flower == min_flower) {
    cout << get_nC2(max_count) << "\n";
  }
  else {
    cout << max_count * min_count << "\n";
  }
  cout << std::flush;
  return 0;
}
