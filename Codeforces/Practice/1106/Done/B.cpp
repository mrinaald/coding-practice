#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct Dish {
  int index = -1;
  ullong count = 0;
  ullong cost = 0;
};

bool comparator(const Dish* lhs, const Dish* rhs) {
  return lhs->cost < rhs->cost;
}

int main(){
  // std::ios::sync_with_stdio(false);
  int n, m;
  scanf("%d %d", &n, &m);

  vector<Dish> dishes(n);
  vector<Dish*> sorted_dishes(n);
  int i, x, d;

  for (i=0; i<n; ++i) {
    scanf("%d", &x);
    dishes[i].index = i;
    dishes[i].count = x;
    sorted_dishes[i] = &(dishes[i]);
  }

  for (i=0; i<n; ++i) {
    scanf("%d", &x);
    dishes[i].cost = x;
  }

  stable_sort(all(sorted_dishes), comparator);

  ullong t;
  ullong cost = 0;
  bool end = false;
  int cheapest_id = 0;
  for (i=0; i<m; ++i) {
    scanf("%d %d", &d, &x);
    if (end) {
      printf("0\n");
      continue;
    }

    d--;
    t = x;
    cost = 0;
    if (dishes[d].count >= t) {
      // we can serve all these dishes
      cost = t * dishes[d].cost;
      dishes[d].count -= t;
      printf("%llu\n", cost);
      continue;
    }
    else {
      if (dishes[d].count > 0) {
        // we can serve some dishes of the requested kind
        cost = dishes[d].cost * dishes[d].count;
        t -= dishes[d].count;
        dishes[d].count = 0;
      }

      while ((t > 0) && (cheapest_id < n)) {
        if (sorted_dishes[cheapest_id]->count == 0) {
          cheapest_id++;
          continue;
        }

        if (sorted_dishes[cheapest_id]->count >= t) {
          cost += (t * sorted_dishes[cheapest_id]->cost);
          sorted_dishes[cheapest_id]->count -= t;
          t = 0;
        }
        else {
          cost += (sorted_dishes[cheapest_id]->count * sorted_dishes[cheapest_id]->cost);
          t -= sorted_dishes[cheapest_id]->count;
          sorted_dishes[cheapest_id]->count = 0;
          cheapest_id++;
        }
      }

      if (t > 0) {
        end = true;
        printf("0\n");
      }
      else {
        printf("%llu\n", cost);
      }
    }
  }

  return 0;
}
