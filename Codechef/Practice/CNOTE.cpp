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

  int t, x, y, n, k;
  int price, pages;
  int i;
  bool lucky;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d %d %d", &x, &y, &k, &n);

    lucky = false;
    for(i=0; i<n; ++i){
      scanf("%d %d", &pages, &price);
      if (price > k)
        continue;
      if (y+pages < x)
        continue;
      lucky = true;
    }

    printf((lucky)?"L":"Unl");
    printf("uckyChef\n");
  }

  return 0;
}
