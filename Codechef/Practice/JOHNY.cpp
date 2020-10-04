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
  std::ios::sync_with_stdio(false);

  int t, n, k;
  int i;
  int x;

  cin >> t;
  while(t--){
    cin >> n;

    vector<int> songs(n);
    for(i=0; i<n; ++i){
      cin >> songs[i];
    }
    cin >> k;

    k--;
    x = 0;
    for(i=0; i<n; ++i){
      if (i == k)
        continue;
      if (songs[i] < songs[k])
        x++;
    }

    cout << x+1 << endl;

  }

  return 0;
}
