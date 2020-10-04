#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define MOD 998244353

int compute_independent_splits(const vector<int> &arr, const map<int, int> &max_index_map);
int pow_mod(int a, int p, int mod);

int main(){
  // std::ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);

  vector<int> arr(n);
  map<int, int> max_index_map;

  for (int i=0; i<n; ++i) {
    scanf("%d", &(arr[i]));

    // It won't matter whether the key exists before or not
    // index `i` will always be the max index for value at a_i
    max_index_map[arr[i]] = i;
  }

  int num_independent_splits = compute_independent_splits(arr, max_index_map);

  printf("%d\n", pow_mod(2, num_independent_splits - 1, MOD));

  return 0;
}


int compute_independent_splits(const vector<int> &arr, const map<int, int> &max_index_map){
  int num_splits = 0;
  int i = 0;
  int max_index = 0;
  int n = arr.size();

  while (i < n) {
    max_index = max(max_index, max_index_map.at(arr[i]));

    if (i == max_index) {
      num_splits++;
    }
    i++;
  }

  return num_splits;
}


int pow_mod(int a, int p, int mod){
  if (p == 0)
    return 1;
  if (p == 1)
    return a;

  ullong temp = pow_mod(a, p/2, mod) % mod;
  temp = (temp * temp) % mod;

  if (p%2 == 0)
    return temp % mod;

  return (temp * (a % mod)) % mod;
}
