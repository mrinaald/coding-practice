#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

#define scanf(s,x) scanf(s, &x);

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
  // std::ios::sync_with_stdio(false);

  int n;
  scanf("%d", n);

  ullong sum = 0;
  int stamps;
  for(int i=0; i<n; ++i){
    scanf("%d", stamps);
    sum += stamps;
  }

  ullong sum2;
  if (n & 1){
    sum2 = (n+1)/2;
    sum2 *= n;
  }
  else{
    sum2 = n/2;
    sum2 *= (n+1);
  }

  printf( (sum==sum2)?"YES\n":"NO\n" );

  return 0;
}
