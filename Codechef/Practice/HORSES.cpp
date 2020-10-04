#include <iostream>
#include <vector>
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

int main(){
  std::ios::sync_with_stdio(false);

  int t, n;
  int i;
  int min_diff;

  cin >> t;

  while(t--){
    cin >> n;

    vector<int> horses(n);
    for(i=0; i<n; ++i){
      cin >> horses[i];
    }

    if (n == 2){
      cout << abs(horses[0] - horses[1]) << endl;
      continue;
    }

    sort(all(horses));
    min_diff = abs(horses[0] - horses[1]);
    for(i=2; i<n; ++i){
      if (abs(horses[i] - horses[i-1]) < min_diff){
        min_diff = abs(horses[i] - horses[i-1]);
      }
    }

    cout << min_diff << endl;
  }

  return 0;
}
