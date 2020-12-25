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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  cin >> str;

  if (str.length() == 1) {
    cout << str;
    return 0;
  }

  int i;
  vector<char> nums;
  int len = str.length();
  for (i=0; i<len; ++i) {
    if (str[i] != '+')
      nums.pb(str[i]);
  }
  sort(all(nums));

  len = nums.size();
  cout << nums[0];
  for (i=1; i<len; ++i) {
    cout << "+" << nums[i];
  }

  cout << "\n";
  cout << std::flush;
  return 0;
}
