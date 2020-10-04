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
  int i;
  int num;

  cin >> n;

  vector<int> odd_arr;
  vector<int> even_arr;

  FOR(i,0,n,1){
    cin >> num;
    if (num%2 == 0){
      even_arr.pb(num);
    }
    else{
      odd_arr.pb(num);
    }
  }

  sort(all(even_arr));
  sort(all(odd_arr));

  int even_size = even_arr.size();
  int odd_size = odd_arr.size();
  int diff;
  llong sum = 0;

  if (even_size==odd_size || even_size==odd_size+1 || odd_size==even_size+1){
    cout << 0 << endl;
  }
  else if (even_size > odd_size){
    diff = even_size - odd_size;
    FOR(i,0,diff-1,1){
      sum += even_arr[i];
    }
    cout << sum << endl;
  }
  else{
    diff = odd_size - even_size;
    FOR(i,0,diff-1,1){
      sum += odd_arr[i];
    }
    cout << sum << endl;
  }

  return 0;
}
