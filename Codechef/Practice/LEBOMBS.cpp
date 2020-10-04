#include <iostream>
#include <string>

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

  int t;
  scanf("%d", &t);

  int n;
  string buildings;
  int i;
  int count;

  while(t--){
    scanf("%d", &n);
    cin >> buildings;

    count = 0;

    for(i=0; i<n; ++i){
      if (buildings[i] != '1')
        continue;

      if (buildings[i] == '1'){
        if (i>0 && buildings[i-1]!='2'){
          buildings[i-1] = '2';
          count++;
        }
        if (i<n && buildings[i+1]=='0'){
          buildings[i+1] = '2';
          count++;
        }

        buildings[i] = '2';
        count++;
      }
    }

    printf("%d\n", n-count);
  }

  return 0;
}
