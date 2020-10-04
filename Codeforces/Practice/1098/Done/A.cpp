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

#define MAX_SUM 1000000009

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct TreeNode {
  int parent = -1;
  llong a = 0;
  llong s = -1;
  vector<size_t> child;
};

int main(){
  // std::ios::sync_with_stdio(false);

  int n;
  scanf("%d", &n);

  vector<TreeNode> tree(n+1);
  int i;
  int p;
  llong s;
  bool is_possible = true;
  llong ans = 0;

  for (i=2; i<=n; ++i) {
    scanf("%d", &p);
    tree[i].parent = p;
    tree[p].child.pb(i);
  }

  for (i=1; i<=n; ++i) {
    scanf("%lld", &s);
    tree[i].s = s;
  }
  tree[1].a = tree[1].s;
  ans = tree[1].a;

  size_t j;
  llong cmin = MAX_SUM;
  llong cmax = -1;
  for (i=2; i<=n; ++i) {
    // don't consider further computations
    if (!is_possible)
      break;

    p = tree[i].parent;

    if (tree[i].s == -1) {
      if (tree[i].child.size() == 0) {
        tree[i].a = 0;
        tree[i].s = tree[p].s;
        continue;
      }

      cmin = MAX_SUM;
      cmax = -2;
      for (j=0; j<tree[i].child.size(); ++j) {
        if (cmin > tree[tree[i].child[j]].s) {
          cmin = tree[tree[i].child[j]].s;
        }
        if (cmax < tree[tree[i].child[j]].s) {
          cmax = tree[tree[i].child[j]].s;
        }
      }

      if (cmin < tree[p].s) {
        is_possible = false;
        break;
      }

      tree[i].a = cmin - tree[p].s;
      tree[i].s = tree[p].s + tree[i].a;
    }
    else {
      tree[i].a = tree[i].s - tree[p].s;
    }

    ans += tree[i].a;
  }

  if (is_possible)
    printf("%lld\n", ans);
  else
    printf("-1\n");

  return 0;
}
