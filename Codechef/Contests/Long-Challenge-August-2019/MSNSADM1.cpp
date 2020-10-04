#include <iostream>
#include <vector>

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
  int t, n, i;
  vector<int> arr(155);
  int max_points;
  int x;

  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);

    for (i=0; i<n; ++i)
      scanf("%d", &arr[i]);

    max_points = 0;
    for (i=0; i<n; ++i){
      scanf("%d", &x);
      x = max((20*arr[i])-(10*x), 0);
      max_points = (x > max_points)?x:max_points;
    }

    printf("%d\n", max_points);
  }

  return 0;
}
