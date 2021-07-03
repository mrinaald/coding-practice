#include <iostream>
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

#define MAX_NUM 1000000

vector<bool> soe(MAX_NUM+1, true);
vector<int> n_prime_factrs(MAX_NUM+1, 0);
vector<int> n_primes(MAX_NUM+1, 0);

void compute_sieve_of_eratosthenes() {
  int i, p;

  soe[0] = soe[1] = false;
  for (p=2; p<=MAX_NUM; ++p) {
    if (soe[p] == false)
      continue;
    n_prime_factrs[p] = 1;
    for(i=p*2; i<=MAX_NUM; i+=p) {
      soe[i] = false;
      n_prime_factrs[i]++;
    }
  }

  for (p=2; p<=MAX_NUM; ++p) {
    n_primes[p] = n_primes[p-1] + (soe[p] == true);
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  compute_sieve_of_eratosthenes();
  // for (int i=1; i<=MAX_NUM; ++i) {
  //   if (i > 200)
  //     break;
  //   if (n_prime_factrs[i] >= 3)
  //     cout << i << " ";
  // }
  // cout << endl;
  // for (int i=1; i<=20; ++i) {
  //   cout << i << " -> " << n_primes[i] << "\n";
  // }

  int t, x, y;

  cin >> t;
  while (t--) {
    cin >> x >> y;

    // cout << " * " << x << " " << y << " " << n_primes[x] << endl;
    if (n_primes[x] <= y) {
      cout << "Chef\n";
      continue;
    }

    cout << "Divyam\n";
  }

  cout << std::flush;
  return 0;
}
