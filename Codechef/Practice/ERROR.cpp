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

enum States {START, ZERO, ZERO_ONE, ONE, ONE_ZERO, END};

int main(){
  std::ios::sync_with_stdio(false);

  int t;
  char ch;
  States state;

  scanf("%d\n", &t);
  while(t--){
    scanf("%c", &ch);
    state = START;

    while(ch!='\n' && ch!=EOF){
      switch(state){
        case START    : state = (ch=='0')?ZERO:ONE; break;
        case ZERO     : state = (ch=='0')?ZERO:ZERO_ONE; break;
        case ZERO_ONE : state = (ch=='0')?END:ONE; break;
        case ONE      : state = (ch=='0')?ONE_ZERO:ONE; break;
        case ONE_ZERO : state = (ch=='0')?ZERO:END; break;
        case END      : break;
      }
      scanf("%c", &ch);
    }

    printf((state==END)?"Good\n":"Bad\n");
  }

  return 0;
}
