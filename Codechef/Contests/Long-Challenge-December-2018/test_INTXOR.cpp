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

  int n, i;
  cin >> n;

  vector<uint> arr(n+1, 0);

  FORE(i, 1, n, 1){
    cin >> arr[i];
  }
  cout << "HELLO" << endl;

  int a, b, c;
  uint ua, ub, uc;
  FOR(i, 0, n, 1){
    cin >> a >> b >> c;
    ua = arr[a];
    ub = arr[b];
    uc = arr[c];
    cout << (ua^ub^uc) << endl;
    cout << "HELLO" << endl;
  }

  return 0;
}
