#include <iostream>
#include <vector>
#include <queue>
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

struct meatball{
  int meat;
  int id;

  meatball(int m, int i){
    meat = m;
    id = i;
  }
};

bool my_comparator(const meatball &lhs, const meatball &rhs){
  return lhs.meat > rhs.meat;
}


int main(){
  std::ios::sync_with_stdio(false);

  int n;
  // cout << "Enter Number of meatballs: ";
  cin >> n;

  // cout << "Enter meat in meatballs:" << endl;

  int i;
  int max_meat = -1;
  vector<int> meat(n+1, 0);

  FORE(i, 1, n, 1){
    cin >> meat[i];
    if( meat[i] > max_meat)
      max_meat = meat[i];
  }

  int t = (n/2)+4;
  int a, b, c, d, e;
  int ai, bi, ci, di, ei;
  int p, q;
  char ch;
  while(t--){
    cin >> ch;

    if(ch == '?'){
      cin >> ai;
      cin >> bi;
      cin >> ci;
      cin >> di;
      cin >> ei;

      meatball a(meat[ai], ai);
      meatball b(meat[bi], bi);
      meatball c(meat[ci], ci);
      meatball d(meat[di], di);
      meatball e(meat[ei], ei);

      vector<meatball> arr;
      arr.pb(a);
      arr.pb(b);
      arr.pb(c);
      arr.pb(d);
      arr.pb(e);
      sort(all(arr), my_comparator);

      q = arr[1].id;
      p = arr[2].id;

      cout << p << " " << q << endl;
    }
    else if(ch == '!'){
      cin >> a;
      if(meat[a] == max_meat){
        cout << "YIPEE!!!" << endl;
        return 0;
      }
      else{
        break;
      }
    }
  }
  cout << "OOPS!!!" << endl;

  return 0;
}
