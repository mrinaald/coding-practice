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

int distSq(int x1, int y1, int x2, int y2);

int main(){
  // std::ios::sync_with_stdio(false);
  int n;
  int x1, y1, x2, y2, x3, y3;
  int count = 0;
  int A, B, C;

  scanf("%d", &n);
  while(n--){
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    if (((x2-x1)*(x3-x1))+((y2-y1)*(y3-y1)) == 0){
      // (x1, y1) is the point of right angle
      A = distSq(x2, y2, x1, y1);
      B = distSq(x3, y3, x1, y1);
      C = distSq(x3, y3, x2, y2);

      if (C == A+B)
        count++;
    }
    else if (((x3-x2)*(x1-x2))+((y3-y2)*(y1-y2)) == 0){
      // (x2, y2) is the point of right angle
      A = distSq(x1, y1, x2, y2);
      B = distSq(x3, y3, x2, y2);
      C = distSq(x3, y3, x1, y1);

      if (C == A+B)
        count++;
    }
    else if (((x1-x3)*(x2-x3))+((y1-y3)*(y2-y3)) == 0){
      // (x3, y3) is the point of right angle
      A = distSq(x2, y2, x3, y3);
      B = distSq(x1, y1, x3, y3);
      C = distSq(x1, y1, x2, y2);

      if (C == A+B)
        count++;
    }
  }

  printf("%d\n", count);

  return 0;
}

int distSq(int x1, int y1, int x2, int y2){
  int d1 = x1-x2;
  int d2 = y1-y2;

  return (d1*d1)+(d2*d2);
}
