#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100000

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

  int t;
  scanf("%d", &t);

  int n;
  int num, size;
  int i;

  while(t--){
    scanf("%d", &n);

    size = 0;
    // vector<int> arr(n);
    vector<bool> present(MAX_N+1, false);

    for (i=0; i<n; ++i){
      // scanf("%d", &arr[i]);
      scanf("%d", &num);
      if (!present[num]){
        present[num] = true;
        size++;
      }
    }

    printf("%d\n", size);
  }

  return 0;
}
