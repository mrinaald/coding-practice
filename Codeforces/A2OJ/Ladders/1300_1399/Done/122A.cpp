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

#define YES "YES\n"
#define NO "NO\n"

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int x = 14;
  int lucky_numbers[14];
  lucky_numbers[0] = 4;
  lucky_numbers[1] = 7;
  lucky_numbers[2] = 44;
  lucky_numbers[3] = 47;
  lucky_numbers[4] = 74;
  lucky_numbers[5] = 77;
  lucky_numbers[6] = 444;
  lucky_numbers[7] = 447;
  lucky_numbers[8] = 474;
  lucky_numbers[9] = 477;
  lucky_numbers[10] = 744;
  lucky_numbers[11] = 747;
  lucky_numbers[12] = 774;
  lucky_numbers[13] = 777;

  int n;
  cin >> n;

  bool is_almost_lucky = false;
  for (int i=0; i < x; ++i) {
    if ( (n % lucky_numbers[i]) != 0 )
      continue;   // `n` is not divisible
    // if ( (n / lucky_numbers[i]) & 1)
    //   continue;   // `n` is divisible, but not "evenly" divisible
    is_almost_lucky = true;
    break;
  }

  if (is_almost_lucky)
    cout << YES;
  else
    cout << NO;

  cout << std::flush;
  return 0;
}
