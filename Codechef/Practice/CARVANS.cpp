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

#define MAX_CARS 10000

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
  std::ios::sync_with_stdio(false);

  int t, n;
  int i;
  int min_speed;
  int count;
  vector<int> speed(MAX_CARS);

  cin >> t;
  while(t--){
    cin >> n;

    for(i=0; i<n; ++i){
      cin >> speed[i];
    }

    min_speed = speed[0];
    count = 1;

    for(i=1; i<n; ++i){
      if (speed[i] <= min_speed){
        count++;
        min_speed = speed[i];
      }
    }

    cout << count << endl;
  }

  return 0;
}
