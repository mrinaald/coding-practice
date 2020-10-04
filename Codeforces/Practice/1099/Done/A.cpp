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

llong get_sum(const int n);

int main(){
  // std::ios::sync_with_stdio(false);

  int ball_w, ball_h;
  int stone_w1, stone_h1;
  int stone_w2, stone_h2;
  int w, h;

  scanf("%d %d", &ball_w, &ball_h);
  scanf("%d %d", &stone_w1, &stone_h1);
  scanf("%d %d", &w, &h);

  if (h > stone_h1) {
    stone_w2 = stone_w1;
    stone_h2 = stone_h1;
    stone_w1 = w;
    stone_h1 = h;
  }
  else {
    stone_w2 = w;
    stone_h2 = h;
  }

  ball_w += (get_sum(ball_h) - get_sum(stone_h1 - 1));
  ball_w = max(0, ball_w - stone_w1);
  ball_w += (get_sum(stone_h1 - 1) - get_sum(stone_h2 - 1));
  ball_w = max(0, ball_w - stone_w2);
  ball_w += get_sum(stone_h2 - 1);

  printf("%d\n", ball_w);

  return 0;
}

llong get_sum(const int n) {
  if (n <= 0)
    return 0;

  if (n & 1) {
    return ((n+1)/2) * n;
  }
  else {
    return (n/2) * (n+1);
  }
}
