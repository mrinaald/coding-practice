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

bool find_seq(int n);
void mod0(vector<uint> &ans, int l, int r);
void mod1(vector<uint> &ans, int l, int r);
void mod3(vector<uint> &ans, int l, int r);

int main(){
  std::ios::sync_with_stdio(false);

  int t, n;

  cin >> t;

  while(t--){
    cin >> n;

    if(find_seq(n) == false)
      return 0;
  }

  return 0;
}

bool find_seq(int n){
  vector<uint> ans(n+1, 0);
  int limit;

  switch(n%4){
  case 0: limit = n; break;
  case 1: limit = n-5; break;
  case 2: limit = n-10; break;
  case 3: limit = n-7; break;
  }

  int i;
  FORE(i, 1, limit, 4){
    mod0(ans, i, i+3);
  }

  switch(n-limit){
  case 5: mod1(ans, limit+1, n); break;
  case 7: mod3(ans, limit+1, n); break;
  case 10: mod1(ans, limit+1, limit+5); mod1(ans, limit+6, n); break;
  }

  cout << "2 ";
  FORE(i, 1, n, 1){
    cout << ans[i] << " ";
  }
  cout << endl << std::flush;
  int rep;
  cin >> rep;
  if(rep == -1)
    return false;
  return true;
}

void mod0(vector<uint> &ans, int l, int r){
  uint v0, v1, v2, v3;

  cout << "1 " << l << " " << l+1 << " " << l+2 << endl << std::flush;
  cin >> v0;

  cout << "1 " << l+1 << " " << l+2 << " " << l+3 << endl << std::flush;
  cin >> v1;

  cout << "1 " << l << " " << l+1 << " " << l+3 << endl << std::flush;
  cin >> v2;

  cout << "1 " << l << " " << l+2 << " " << l+3 << endl << std::flush;
  cin >> v3;

  if((v0==-1) || (v1==-1) || (v2==-1) || (v3==-1))
    return;

  uint a = v0^v2^v3;
  uint b = v0^v1^v2;
  uint c = v0^v1^v3;
  uint d = v1^v2^v3;

  ans[l] = a;
  ans[l+1] = b;
  ans[l+2] = c;
  ans[l+3] = d;
}

void mod1(vector<uint> &ans, int l, int r){
  uint v0, v1, v2, v3, v4;

  cout << "1 " << l << " " << l+1 << " " << l+2 << endl << std::flush;
  cin >> v0;

  cout << "1 " << l+1 << " " << l+2 << " " << l+3 << endl << std::flush;
  cin >> v1;

  cout << "1 " << l+2 << " " << l+3 << " " << l+4 << endl << std::flush;
  cin >> v2;

  cout << "1 " << l << " " << l+1 << " " << l+4 << endl << std::flush;
  cin >> v3;

  cout << "1 " << l << " " << l+3 << " " << l+4 << endl << std::flush;
  cin >> v4;

  if((v0==-1) || (v1==-1) || (v2==-1) || (v3==-1) || (v4==-1))
    return;

  uint a = v1^v2^v3;
  uint b = v0^v2^v4;
  uint c = v1^v3^v4;
  uint d = v0^v2^v3;
  uint e = v0^v1^v4;

  ans[l] = a;
  ans[l+1] = b;
  ans[l+2] = c;
  ans[l+3] = d;
  ans[l+4] = e;
}

void mod3(vector<uint> &ans, int l, int r){
  uint v0, v1, v2, v3, v4, v5, v6;

  cout << "1 " << l << " " << l+1 << " " << l+2 << endl << std::flush;
  cin >> v0;

  cout << "1 " << l+1 << " " << l+2 << " " << l+3 << endl << std::flush;
  cin >> v1;

  cout << "1 " << l+2 << " " << l+3 << " " << l+4 << endl << std::flush;
  cin >> v2;

  cout << "1 " << l+3 << " " << l+4 << " " << l+5 << endl << std::flush;
  cin >> v3;

  cout << "1 " << l+4 << " " << l+5 << " " << l+6 << endl << std::flush;
  cin >> v4;

  cout << "1 " << l << " " << l+1 << " " << l+6 << endl << std::flush;
  cin >> v5;

  cout << "1 " << l << " " << l+5 << " " << l+6 << endl << std::flush;
  cin >> v6;

  if((v0==-1) || (v1==-1) || (v2==-1) || (v3==-1) || (v4==-1) || (v5==-1) || (v6==-1))
    return;

  uint ag = v0^v1^v3^v4;
  uint b = v5^ag;
  uint f = v6^ag;
  uint e = v1^v2^b;
  uint c = v2^v3^f;
  uint a = v0^b^c;
  uint d = v1^b^c;
  uint g = v4^e^f;

  ans[l] = a;
  ans[l+1] = b;
  ans[l+2] = c;
  ans[l+3] = d;
  ans[l+4] = e;
  ans[l+5] = f;
  ans[l+6] = g;
}
