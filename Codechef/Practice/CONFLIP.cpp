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

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
  std::ios::sync_with_stdio(false);

  int t, g, i, n, q;

  cin >> t;
  while(t--){
    cin >> g;
    while(g--){
      cin >> i >> n >> q;

      if (n%2 == 0){
        cout << n/2 << endl;
      }
      else if (i == q){
        cout << n/2 << endl;
      }
      else{
        cout << n/2 + 1 << endl;
      }
    }
  }

  return 0;
}
