#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct Node {
  bool is_visited = false;
  bool in_heap = false;
  vector<int> children;
};

int main(){
  // std::ios::sync_with_stdio(false);
  int n, m;
  scanf("%d %d", &n, &m);

  vector<Node> park(n + 1);
  int i, x, y;
  for (i=0; i<m; ++i) {
    scanf("%d %d", &x, &y);

    park[x].children.pb(y);
    park[y].children.pb(x);
  }

  priority_queue<int, vector<int>, greater<int>> park_heap;
  park_heap.push(1);
  park[1].in_heap = true;

  while(!park_heap.empty()) {
    x = park_heap.top();
    park_heap.pop();

    park[x].is_visited = true;

    printf("%d ", x);
    for (i=0; i < park[x].children.size(); ++i) {
      y = park[x].children[i];
      if ((!park[y].is_visited) && (!park[y].in_heap)) {
        park_heap.push(y);
        park[y].in_heap = true;
      }
    }
  }

  return 0;
}
