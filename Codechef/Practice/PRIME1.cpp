#include <iostream>
#include <vector>
#include <cmath>

#define MAX_SIZE 1000000

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

vector<bool> SOE(MAX_SIZE, true);
vector<int> primes;

void computeSOE();
bool checkPrime(int n);

int main(){
  // std::ios::sync_with_stdio(false);

  computeSOE();
  int t, m, n;
  int i;

  cin >> t;
  while(t--){
    cin >> m >> n;

    for(i=m; i<=n; ++i){
      if (i<MAX_SIZE){
        if (SOE[i])
          printf("%d\n", i);
          // cout << i << endl;
      }
      else if(checkPrime(i))
        printf("%d\n", i);
        // cout << i << endl;
    }
    // cout << endl;
    printf("\n");
  }

  return 0;
}

void computeSOE(){
  int i, j;
  SOE[0] = SOE[1] = false;

  for(i=2; i<MAX_SIZE; ++i){
    if (!SOE[i])
      continue;

    primes.pb(i);
    for(j=2*i; j<MAX_SIZE; j+=i)
      SOE[j] = false;
  }
}

bool checkPrime(int n){
  int i;
  int lim = ceil(sqrt(n));
  int size = primes.size();
  // for(i=2; i<=lim; ++i){
  //   if (i<MAX_SIZE && !SOE[i])
  //     continue;
  //   if (n%i == 0)
  //     return false;
  // }
  for(i=0; i<size; ++i){
    if (primes[i] > lim)
      break;
    if (n%primes[i] == 0)
      return false;
  }
  return true;
}
