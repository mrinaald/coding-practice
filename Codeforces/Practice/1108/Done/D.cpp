#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;


char get_new_lamp(const char left, const char right);

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string garland;
  cin >> garland;
  garland += " ";

  int i;
  int changes = 0;
  for (i=1; i<n; ++i) {
    if (garland[i] == garland[i-1]) {
      changes++;
      garland[i] = get_new_lamp(garland[i-1], garland[i+1]);
    }
  }

  cout << changes << "\n" << garland << endl;

  return 0;
}

char get_new_lamp(const char left, const char right) {
  if (('B' != left) && ('B' != right))
    return 'B';
  if (('G' != left) && ('G' != right))
    return 'G';
  if (('R' != left) && ('R' != right))
    return 'R';

  return ' ';
}
