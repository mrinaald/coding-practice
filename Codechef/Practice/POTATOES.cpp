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

#define ARRSIZE 3000

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

bool soe[ARRSIZE];

void computeSOE();

int main(){
  // std::ios::sync_with_stdio(false);

  computeSOE();

  int t, x, y, z;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &x, &y);

    z = 1;
    x += y;
    while(true){
      if (soe[x+z])
        break;
      else
        z++;
    }

    printf("%d\n", z);
  }

  return 0;
}

void computeSOE(){
  soe[0] = soe[1] = false;
  int i, j;

  for(i=2; i<ARRSIZE; ++i)
    soe[i] = true;

  for(i=2; i<ARRSIZE; ++i){
    if (!soe[i])
      continue;
    for(j=2*i; j<ARRSIZE; j+=i)
      soe[j] = false;
  }
}
