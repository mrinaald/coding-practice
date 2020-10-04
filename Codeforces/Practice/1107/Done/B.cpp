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
  // std::ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);

  ullong k;
  int x;

  while (n--) {
    scanf("%llu %d", &k, &x);

    k = ((k - 1) * 9ULL) + x;
    printf("%llu\n", k);
  }
  return 0;
}
