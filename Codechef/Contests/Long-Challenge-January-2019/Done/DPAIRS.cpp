#include <iostream>
#include <vector>
#include <unordered_map>
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

struct Element {
  int value;
  int index;
};

bool myComparator(const Element &lhs, const Element &rhs) {
  return lhs.value < rhs.value;
}

int main(){
  // std::ios::sync_with_stdio(false);
  int n, m;
  int i;
  int x;

  scanf("%d %d", &n, &m);

  vector<Element> A(n);
  vector<Element> B(m);

  for (i=0; i<n; ++i) {
    scanf("%d", &x);
    A[i].value = x;
    A[i].index = i;
  }

  for (i=0; i<m; ++i) {
    scanf("%d", &x);
    B[i].value = x;
    B[i].index = i;
  }

  sort(A.begin(), A.end(), myComparator);
  sort(B.begin(), B.end(), myComparator);

  unordered_map<int, bool> sum_map;

  i = 0;
  int limit = n + m -1;
  int a, b;
  a = 0;
  b = m-1;

  while (i < limit) {
    if (b < 0) {
      a++;
      b = m-1;
    }

    x = A[a].value + B[b].value;
    if (sum_map.find(x) == sum_map.end()) {
      // printf("%d %d\n", A[a].value, B[b].value);
      printf("%d %d\n", A[a].index, B[b].index);
      sum_map.insert(make_pair(x, true));
      b--;
      i++;
    }
    else {
      a++;
      b = m-1;
    }
  }

  return 0;
}
