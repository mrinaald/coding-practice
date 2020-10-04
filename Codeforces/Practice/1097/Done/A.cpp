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
  // std::ios::sync_with_stdio(false);

  char table[3];
  char hand[5][3];

  scanf("%s", table);
  scanf("%s %s %s %s %s", hand[0], hand[1], hand[2], hand[3], hand[4]);

  bool can_play = false;

  for (int i=0; i<5; ++i) {
    if (table[0] == hand[i][0]) {
      can_play = true;
      break;
    }
  }

  if (can_play) {
    printf("YES\n");
    return 0;
  }

  for (int i=0; i<5; ++i) {
    if (table[1] == hand[i][1]) {
      can_play = true;
      break;
    }
  }

  if (can_play) {
    printf("YES\n");
    return 0;
  }

  printf("NO\n");

  return 0;
}
