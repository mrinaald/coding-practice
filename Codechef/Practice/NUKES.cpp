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

  int a, n, k;
  int i, x;
  cin >> a >> n >> k;

  if (n==0 || a==0){
    k--;
    for(i=0; i<k; ++i)
      cout << "0 ";
    k++;
    cout << 0 << endl;
    return 0;
  }

  vector<int> reactors(k, 0);
  n++;
  i = 0;

  while(a>0){
    x = a%n;
    a = a/n;

    if (i<k)
      reactors[i] = x;
    i++;
  }

  k--;
  for(i=0; i<k; ++i)
    cout << reactors[i] << " ";
  k++;
  cout << reactors[k-1] << endl;

  return 0;
}
