#include <iostream>
#include <vector>
#include <algorithm>

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

bool my_comparator(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
  return lhs.first < rhs.first;
}

int main(){
  // std::ios::sync_with_stdio(false);
  int n, k, i;

  scanf("%d", &n);
  scanf("%d", &k);

  vector< std::pair<int, int> > arr(n);
  vector<int> color(n, 0);

  for (i=0; i<n; ++i) {
    scanf("%d", &(arr[i].first));
    arr[i].second = i;
  }

  sort(all(arr), my_comparator);

  int c = 0;
  bool is_possible = true;

  for (i=0; i<n; ++i) {
    if (i >= k) {
      if (arr[i-k].first == arr[i].first) {
        is_possible = false;
        break;
      }
      color[arr[i].second] = (c % k) + 1;
      c++;
    }
    else {
      color[arr[i].second] = c+1;
      c++;
    }
  }

  if (is_possible) {
    printf("YES\n");
    for (i=0; i<n; ++i) {
      printf("%d ", color[i]);
    }
    printf("\n");
  }
  else {
    printf("NO\n");
  }

  return 0;
}
