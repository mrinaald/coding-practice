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

  int t;
  // char cards[100005];
  int len;
  char ch;
  int one_count;

  scanf("%d\n", &t);
  while(t--){
    len = 0;
    one_count = 0;

    scanf("%c", &ch);
    while(ch!='\n' && ch!=EOF){
      // cards[len++] = ch;
      one_count += (ch - '0');
      scanf("%c", &ch);
    }
    // cards[len] = '\0';

    if (!one_count){
      printf("LOSE\n");
      continue;
    }

    printf((one_count & 1)?"WIN\n":"LOSE\n");
  }

  return 0;
}
