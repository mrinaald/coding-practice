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

  int n, m;
  scanf("%d %d", &n, &m);

  vector<int> index(n, 0);
  vector<int> arr(m, 0);

  int i;
  int p;
  for (i=0; i<m; ++i) {
    scanf("%d", &p);
    p--;    // decrement for making range 0 to n-1

    arr[index[p]]++;
    if (arr[index[p]] == n) {
      printf("1");
    }
    else {
      printf("0");
    }
    index[p]++;
  }

  printf("\n");

  return 0;
}
