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

int computeGCD(int a, int b){
  if (a < b)
    return computeGCD(b, a);

  if (b == 0)
    return a;

  if (b == 1)
    return 1;

  return computeGCD(b, a%b);
}

int main(){
  // std::ios::sync_with_stdio(false);

  int t, n, i;
  int gcd;
  scanf("%d", &t);

  while(t--){
    scanf("%d", &n);

    vector<int> arr(n);
    for(i=0; i<n; ++i){
      scanf("%d", &(arr[i]));
    }

    if (n == 1){
      printf("%d\n", arr[0]);
      continue;
    }

    gcd = computeGCD(arr[0], arr[1]);
    for (i=2; i<n; ++i){
      if (gcd == 1)
        break;

      gcd = computeGCD(arr[i], gcd);
    }

    printf("%d\n", gcd);
  }

  return 0;
}
