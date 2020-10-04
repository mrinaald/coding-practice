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

  int n, k;
  scanf("%d %d", &n, &k);

  vector< vector<int> > arr(k, vector<int>(2, 0));

  int i;
  int t;
  int s = 0;
  int e = 0;
  for (i=0; i<n; ++i) {
    scanf("%d", &t);
    if (t == -1) {
      arr[i%k][0] += 1;
      s++;
    }
    else {
      arr[i%k][1] += 1;
      e++;
    }
  }

  int rem_tabs = 0;
  for (i=0; i<k; ++i) {
    t = abs((e-arr[i][1]) - (s-arr[i][0]));
    // printf("%d %d %d %d %d", e, arr[i][1], s, arr[i][0], t);
    if (t > rem_tabs)
      rem_tabs = t;
  }

  printf("%d\n", rem_tabs);

  return 0;
}
