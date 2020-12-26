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

  ullong n;
  cin >> n;

  switch(n) {
  case 0: cout << "0 0 0" << endl; return 0;
  case 1: cout << "0 0 1" << endl; return 0;
  case 2: cout << "0 1 1" << endl; return 0;
  }

  ullong fib[60];     // Fib(59) = 956722026041 > 10^9
  fib[0] = 0;
  fib[1] = fib[2]= 1;

  int i;
  for (i=3; i<60; ++i) {
    fib[i] = fib[i-1] + fib[i-2];
    if (fib[i] == n)
      break;
  }

  cout << fib[i-4] << " " << fib[i-3] << " " << fib[i-1] << "\n";
  cout << std::flush;
  return 0;
}
