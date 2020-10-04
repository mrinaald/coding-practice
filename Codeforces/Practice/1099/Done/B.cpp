#include <iostream>
#include <cmath>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
  // std::ios::sync_with_stdio(false);

  int n;
  scanf("%d", &n);

  llong sqt = (int)(sqrt(n));
  llong sq = (sqt*sqt);

  if ( sq == n ) {
    // this is a perfect square
    printf("%lld\n", 2 * sqt);
  }
  else {
    // this is not a perfect square
    llong r_sqt = sqt+1;
    llong d = (r_sqt*r_sqt) - sq;
    if (n <= (sq + (d/2)) ) {
      printf("%lld\n", 2 * sqt + 1);
    }
    else {
      printf("%lld\n", 2 * sqt + 2);
    }
  }

  return 0;
}
