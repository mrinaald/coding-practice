#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_CAVES 100000

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

  int t, n;
  int i;
  vector<ullong> cave(MAX_CAVES+2);
  vector<ullong> zombie(MAX_CAVES+2);
  llong left;
  llong right;

  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);

    for (i=0; i<n; ++i)
      scanf("%llu", &cave[i]);

    for (i=0; i<n; ++i)
      scanf("%llu", &zombie[i]);

    vector<int> left_cave(n, 0);
    vector<int> right_cave(n, 0);

    for (i=0; i<n; ++i){
      left = i - cave[i];
      left = (left > 0)?left:0;
      left_cave[left] += 1;

      right = i + cave[i];
      right = (right >= n)?n-1:right;
      right_cave[right] += 1;
    }


    // for (i=0; i<n; ++i){
    //   printf("%d ", left_cave[i]);
    // }
    // printf("\n");
    // for (i=0; i<n; ++i){
    //   printf("%d ", right_cave[i]);
    // }
    // printf("\n");


    left = 0;
    for (i=0; i<n; ++i){
      left += left_cave[i];
      cave[i] = left;
      left -= right_cave[i];
    }

    // for (i=0; i<n; ++i){
    //   printf("%llu ", cave[i]);
    // }
    // printf("\n");

    sort(cave.begin(), cave.begin()+n);
    sort(zombie.begin(), zombie.begin()+n);

    for (i=0; i<n; ++i){
      if (cave[i] != zombie[i])
        break;
    }

    printf((i==n)?"YES\n":"NO\n");
  }

  return 0;
}
