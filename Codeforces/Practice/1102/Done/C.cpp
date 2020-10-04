#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
  // std::ios::sync_with_stdio(false);
  int n, x, y, a, i;
  int leq = 0;

  scanf("%d", &n);
  scanf("%d", &x);
  scanf("%d", &y);

  for (i=0; i<n; ++i) {
    scanf("%d", &a);
    if (a <= x)
      leq++;
  }

  if (x > y) {
    printf("%d\n", n);
  }
  else {
    printf("%d\n", (leq + 1) / 2);
  }

  return 0;
}
