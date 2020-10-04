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

  int n;
  scanf("%d", &n);

  int i, j;
  vector<int> arr(n+1);
  vector<bool> visited(n+1, false);

  for(i=1; i<=n; ++i){
    scanf("%d", &arr[i]);
    visited[i] = false;
  }

  vector<vector<int>> ans;
  for (i=1; i<=n; ++i){
    if (visited[i])
      continue;

    vector<int> temp;

    visited[i] = true;
    temp.pb(i);
    j = arr[i];
    while(j != i){
      visited[j] = true;
      temp.pb(j);
      j = arr[j];
    }
    temp.pb(j);

    ans.pb(temp);
  }

  printf("%d\n", ans.size());
  for (i=0; i<ans.size(); ++i){
    for (j=0; j<ans[i].size(); ++j){
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}
