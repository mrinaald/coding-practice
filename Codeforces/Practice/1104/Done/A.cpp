#include <iostream>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
  // std::ios::sync_with_stdio(false);
  int n, k;
  scanf("%d", &n);

  k = n;
  for (int i=9; i>1; --i) {
    if ( (n%i) == 0 ) {
      k = n / i;
      break;
    }
  }

  // Printing the numer of digits
  printf("%d\n", k);

  // Printing the digits
  int lim = k;
  k = n / k;
  for (int i=0; i<lim; ++i) {
    printf("%d ", k);
  }
  printf("\n");

  return 0;
}
