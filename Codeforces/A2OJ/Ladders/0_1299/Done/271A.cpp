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

#define MAX_YEAR 9999
#define MAX_DIGITS 4

int power10[5] = {1, 10, 100, 1000, 10000};

bool is_beautiful_year(int year) {
  int di, dj;

  for (int i=1; i < MAX_DIGITS; ++i) {
    for (int j=i+1; j <= MAX_DIGITS; ++j) {
      di = (year % power10[i]) / power10[i-1];
      dj = (year % power10[j]) / power10[j-1];

      if (di == dj)
        return false;
    }
  }
  return true;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int year;
  cin >> year;

  ++year;
  for (; year <= MAX_YEAR; ++year) {
    if (is_beautiful_year(year)) {
      cout << year << endl;
      break;
    }
  }

  cout << std::flush;
  return 0;
}
