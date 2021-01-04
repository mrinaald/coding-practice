#include <iostream>
#include <cmath>
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

#define MAX_LIMIT 1000011

vector<bool> sieve_of_eratosthenes(MAX_LIMIT, true);

void compute_soe() {
  sieve_of_eratosthenes[0] = sieve_of_eratosthenes[1] = false;

  llong i, j;
  for (i=2; i<MAX_LIMIT; ++i) {
    if (!sieve_of_eratosthenes[i])
      continue;

    for (j=2*i; j<MAX_LIMIT; j+=i) {
      sieve_of_eratosthenes[j] = false;
    }
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  compute_soe();

  int n;
  cin >> n;

  ullong x;
  ullong s;
  while (n--) {
    cin >> x;

    s = sqrt(x);
    if ((s * s) != x) {
      cout << "NO\n";
    }
    else if (sieve_of_eratosthenes[s]) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }

  cout << std::flush;
  return 0;
}
