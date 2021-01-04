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

#define MAX_N 10000000

bool prime_numbers[MAX_N + 1];

void compute_sieve_of_eratosthenes(const int n) {
  prime_numbers[0] = prime_numbers[1] = false;

  int p, c;
  for (p=2; p<=MAX_N; ++p)
    prime_numbers[p] = true;

  int cnt = 0;
  for (p=2; p<=MAX_N; ++p) {
    if (!prime_numbers[p])
      continue;

    ++cnt;
    if (cnt == n)
      break;
    for (c=2*p; c<=MAX_N; c += p) {
      prime_numbers[c] = false;
    }
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

  compute_sieve_of_eratosthenes(n);

  int p;
  for (p=2; n > 0 && p<=MAX_N; ++p) {
    if (prime_numbers[p]) {
      if (n == 1)
        cout << p;
      else
        cout << p << " ";

      --n;
    }
  }

  cout << endl;
  return 0;
}
