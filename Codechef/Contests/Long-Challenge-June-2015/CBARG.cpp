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

int main(){
  std::ios::sync_with_stdio(false);

  int T, N;
  int i;
  ullong prev_mem = 0;
  ullong total_allocated = 0;
  ullong mem;

  cin >> T;

  while(T--){
    cin >> N;

    if (N == 1){
      cin >> mem;
      cout << mem << endl;
      continue;
    }

    prev_mem = 0;
    total_allocated = 0;

    for(i=0; i<N; ++i){
      cin >> mem;

      if (mem > prev_mem)
        total_allocated += (mem - prev_mem);

      prev_mem = mem;
    }

    cout << total_allocated << endl;
  }

  return 0;
}
