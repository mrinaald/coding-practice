#include <iostream>
#include <cmath>

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

double computeVolume(double l, int p, int s);
double largestVolume(int p, int s);

int main(){
  // std::ios::sync_with_stdio(false);

  int t;
  int P, S;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &P, &S);

    printf("%.2lf\n", largestVolume(P, S));
  }

  return 0;
}

double largestVolume(int p, int s){
  // l = (1/12)*(p +- sqrt(p^2 - 24s))

  double l;
  double d = sqrt(p*p - 24*s);

  l = (p + d)/12;
  double v1 = computeVolume(l, p, s);

  l = (p - d)/12;
  double v2 = computeVolume(l, p, s);

  return max(v1, v2);
}

double computeVolume(double l, int p, int s){
  // V = l^3 - (P/4)l^2 + (S/2)l
  double V = l*l*l - (p*l*l)/4 + (s*l)/2;

  return V;
}
