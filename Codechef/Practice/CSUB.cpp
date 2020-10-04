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

  int t, n;
  int i;
  char ch;
  int left;
  long int count;

  scanf("%d", &t);
  while(t--){
    scanf("%d\n", &n);

    left = 0;
    count = 0;
    for(i=0; i<n; ++i){
      scanf("%c", &ch);
      if (ch == '1'){
        left++;
        count += left;
      }
    }

    printf("%ld\n", count);
  }

  return 0;
}
