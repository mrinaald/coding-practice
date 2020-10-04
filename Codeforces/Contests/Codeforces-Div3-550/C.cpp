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

  int n;
  cin >> n;

  int i;
  vector<int> arr(n);

  FOR(i, 0, n, 1){
    cin >> arr[i];
  }

  sort(all(arr));

  vector<int> inc_arr;
  vector<int> dec_arr;

  dec_arr.pb(arr[0]);
  int ds = 1;
  int is = 0;

  FOR(i, 1, n, 1){
    if (arr[i] == dec_arr[ds-1]){
      if (is == 0){
        inc_arr.pb(arr[i]);
        is++;
      }
      else if(arr[i] != inc_arr[is-1]){
        inc_arr.pb(arr[i]);
        is++;
      }
      else{
        cout << "NO" << endl;
        return 0;
      }
    }
    else{
      dec_arr.pb(arr[i]);
      ds++;
    }
  }

  cout << "YES" << endl;
  cout << is << endl;
  FOR(i, 0, is, 1){
    cout << inc_arr[i] << ' ';
  }
  cout << endl;

  cout << ds << endl;
  for(i=ds-1; i>=0; i--){
    cout << dec_arr[i] << " ";
  }
  cout << endl;

  return 0;
}
