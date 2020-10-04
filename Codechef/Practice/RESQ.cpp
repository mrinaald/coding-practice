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

  int t;
  long int n;
  long int x, y;
  long int min_diff;
  long int n_2;

  scanf("%d", &t);
  while(t--){
    scanf("%ld", &n);

    x = 1;
    min_diff = n;
    n_2 = sqrt(n);
    while(true){
      if (x > n_2)
        break;
      if (n%x != 0){
        x++;
        continue;
      }

      y = n/x;
      if (y < x)
        break;

      if ((y-x) < min_diff)
        min_diff = y-x;

      x++;
    }

    printf("%ld\n", min_diff);
  }

  return 0;
}
