#include <iostream>

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

  int q;
  ullong l, r, d;

  ullong l_quo;
  ullong l_rem;
  ullong r_quo;

  scanf("%d", &q);

  while (q--) {
    scanf("%llu %llu %llu", &l, &r, &d);

    l_quo = l / d;
    l_rem = l % d;
    r_quo = r / d;

    if (l_quo == 0) {
      printf("%llu\n", (r_quo + 1) * d);
    }
    else if (l_quo == 1) {
      if (l_rem == 0) {
        printf("%llu\n", (r_quo + 1) * d);
      }
      else {
        printf("%llu\n", d);
      }
    }
    else {
      printf("%llu\n", d);
    }
  }

  return 0;
}
