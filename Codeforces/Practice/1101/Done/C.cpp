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

bool my_lt_comparator(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
  if (lhs.first < rhs.first)
    return true;
  else if ((lhs.first == rhs.first) && (lhs.second < rhs.second))
    return true;
  else
    return false;
}

bool my_le_comparator(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
  if (lhs.first < rhs.first)
    return true;
  else if ((lhs.first == rhs.first) && (lhs.second <= rhs.second))
    return true;
  else
    return false;
}

int main(){
  // std::ios::sync_with_stdio(false);

  int T;
  int n;
  int l, r;
  int i;
  vector< std::pair<int, int> > arr(100005);
  vector< std::pair<int, int> > sorted_arr(100005);

  scanf("%d", &T);

  while (T--) {
    scanf("%d", &n);

    for (i=0; i<n; ++i) {
      scanf("%d %d", &l, &r);
      arr[i] = mp(l, r);
      sorted_arr[i] = mp(l, r);
    }

    sort(sorted_arr.begin(), sorted_arr.begin() + n, my_lt_comparator);

    l = -1;
    r = sorted_arr[0].second;
    for (i=1; i<n; ++i) {
      if (r < sorted_arr[i].first) {
        l = i-1;
        break;
      }
      r = max(r, sorted_arr[i].second);
    }

    if (l == -1) {
      printf("-1\n");
      continue;
    }

    for (i=0; i<n; ++i) {
      if ( my_le_comparator(arr[i], sorted_arr[l]) )
        printf("1 ");
      else
        printf("2 ");
    }
    printf("\n");
  }

  return 0;
}
