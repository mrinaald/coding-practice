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

  int t, n, m;
  int i, x;

  cin >> t;
  while(t--){
    cin >> n >> m;

    vector<bool> jobs(n, true);
    for(i=0; i<m; ++i){
      cin >> x;
      jobs[x-1] = false;
    }

    vector<int> assist;
    x = 0;
    for(i=0; i<n; ++i){
      if (jobs[i] == false)
        continue;
      if (x%2 == 0)
        cout << i+1 << " ";
      else
        assist.pb(i+1);
      x++;
    }

    cout << endl;
    for(i=0; i<assist.size(); ++i){
      cout << assist[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
