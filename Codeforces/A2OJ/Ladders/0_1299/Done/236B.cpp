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

#define M 1073741824

void compute_sieve_of_eratosthenes(vector<int> &arr) {
  arr[0] = 0;
  arr[1] = 1;

  int n = arr.size();
  int i, j;
  for (i=2; i<n; ++i) {
    if (arr[i] != 0)
      continue;
    arr[i] = i;
    for (j=2*i; j<n; j+=i) {
      if (arr[j] == 0)
        arr[j] = i;
    }
  }
}

void compute_prime_factors(vector<vector<std::pair<int, int>>> &prime_factors,
                           const vector<int> &sieve_of_eratosthenes) {
  int i, n, p;
  int cnt;
  int size = prime_factors.size();
  for (i=2; i<size; ++i) {
    p = sieve_of_eratosthenes[i];
    n = i / p;
    cnt = 1;
    while (n > 1) {
      if (p == sieve_of_eratosthenes[n]) {
        cnt++;
      }
      else {
        prime_factors[i].pb(mp(p, cnt));
        p = sieve_of_eratosthenes[n];
        cnt = 1;
      }
      n /= p;
    }
    prime_factors[i].pb(mp(p, cnt));
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int A, B, C;
  cin >> A >> B >> C;

  int m = max(max(A, B), C);
  m = 100;

  vector<int> sieve_of_eratosthenes(m+1, 0);
  compute_sieve_of_eratosthenes(sieve_of_eratosthenes);

  vector<vector<std::pair<int, int>>> prime_factors(m+1, vector<std::pair<int, int>>());
  compute_prime_factors(prime_factors, sieve_of_eratosthenes);

  int a, b, c;
  int as, bs, cs, ps;
  int i, j;
  int x;
  llong ans = 0;
  std::pair<int, int>* p1;
  std::pair<int, int>* p2;
  for (a=1; a<=A; ++a) {
    as = prime_factors[a].size();

    for (b=1; b<=B; ++b) {
      bs = prime_factors[b].size();
      vector<std::pair<int, int>> powers;

      // Combining powers of prime factors for a & b
      i = j = 0;
      while ((i < as) && (j < bs)) {
        p1 = &(prime_factors[a][i]);
        p2 = &(prime_factors[b][j]);
        if (p1->first == p2->first) {
          powers.pb(mp(p1->first, p1->second + p2->second));
          ++i; ++j;
        }
        else if (p1->first < p2->first) {
          powers.pb(*p1);
          ++i;
        }
        else {
          powers.pb(*p2);
          ++j;
        }
      }

      while (i < as) {
        powers.pb(prime_factors[a][i]);
        ++i;
      }

      while (j < bs) {
        powers.pb(prime_factors[b][j]);
        ++j;
      }
      //////////////////////////////////////////////////
      ps = powers.size();

      for (c=1; c<=C; ++c) {
        cs = prime_factors[c].size();

        i = j = 0;
        x = 1;
        while ((i < ps) && (j < cs)) {
          p1 = &(powers[i]);
          p2 = &(prime_factors[c][j]);

          if (p1->first == p2->first) {
            x *= (p1->second + p2->second + 1);
            ++i; ++j;
          }
          else if (p1->first < p2->first) {
            x *= (p1->second + 1);
            ++i;
          }
          else {
            x *= (p2->second + 1);
            ++j;
          }
        }

        while (i < ps) {
          x *= (powers[i].second + 1);
          ++i;
        }

        while (j < cs) {
          x *= (prime_factors[c][j].second + 1);
          ++j;
        }

        ans = (ans + (x % M)) % M;
      }
    }
  }

  cout << ans << endl;
  cout << std::flush;
  return 0;
}
