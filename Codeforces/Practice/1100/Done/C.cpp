#include <iostream>

// The _USE_MATH_DEFINES flag is required before cmath
// in order to have M_PI available
#define _USE_MATH_DEFINES
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

  float n, r;
  scanf("%f %f", &n, &r);

  double s = sin(M_PI/n);

  double ans = (r * s) / (1 - s);

  printf("%.7f\n", ans);

  return 0;
}
