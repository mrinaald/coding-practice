#include <iostream>
#include <array>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define MAX_NODES 200001

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct TreeNode {
  int a;
  int p;
  vector<int> children;
};

std::array<TreeNode, MAX_NODES> tree;

int main(){
  // std::ios::sync_with_stdio(false);

  int n;
  int i;
  scanf("%d", &n);

  for (i=0; i<n; ++i) {
    scanf("%d", &(tree[i].a));
  }

  int x, y;
  for (i=1; i<n; ++i) {
    scanf("%d %d", &x, &y);
    --x; --y;
    if ( x < y ) {
      tree[x].children.pb(y);
      tree[y].p = x;
    }
    else {
      tree[y].children.pb(x);
      tree[x].p = y;
    }
  }

  return 0;
}
