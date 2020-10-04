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

int c;
int tc = 1000;

int func(int l, int r);

int main(){
  std::ios::sync_with_stdio(false);

  int N;
  cin >> N >> c;

  int ans;
  cout << "1 " << 1 << endl << std::flush;
  cin >> ans;
  tc--;

  if (ans != 1){
    ans = func(1, N);
  }

  cout << "3 " << ans << endl << std::flush;

  // int pow_2 = 1;
  // int limit = 1;
  // int x;
  // int tc = 1000;

  // while(pow_2 <= N){
  //   cout << "1 " << pow_2 << endl << std::flush;
  //   cin >> x;
  //   tc--;

  //   if(x == 0){
  //     limit = pow_2;
  //     pow_2 *= 2;
  //   }
  //   else if(x == 1){
  //     cout << 2 << endl << std::flush;
  //     tc -= c;
  //     break;
  //   }
  //   else if(x == -1){
  //     return 0;
  //   }
  // }

  // int i;
  // pow_2 = (pow_2 < N)?pow_2:N;

  // FOR(i, limit+1, pow_2, 1){
  //   cout << "1 " << i << endl << std::flush;
  //   cin >> x;
  //   if(x == 1){
  //     cout << "3 " << i << endl << std::flush;
  //     return 0;
  //   }
  //   else if(x == -1){
  //     return 0;
  //   }
  // }

  // cout << "3 " << pow_2 << endl << std::flush;

  return 0;
}

int func(int l, int r){
  if(l == (r-1)){
    return r;
  }

  int x = 1;
  int y = x+l;
  int prev_y = l;
  int ret;

  while(y < r){
    cout << "1 " << y << endl << std::flush;
    cin >> ret;
    tc--;
    if(tc <= 0)
      return -1;

    if(ret == 0){
      x *= 2;
      prev_y = y;
      y = x+l;
    }
    else if(ret == 1){
      if (prev_y == (y-1)){
        return y;
      }
      tc -= c;
      if(tc <= 0)
        return -1;
      cout << "2" << endl << std::flush;
      return func(prev_y, y);
    }
    else{
      return -1;
    }
  }

  return func(prev_y, r);
}
