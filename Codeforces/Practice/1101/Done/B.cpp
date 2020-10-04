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

  char ch;

  int state_count[3];
  state_count[2] = -1;
  int state = 0;

  while (scanf("%c", &ch)) {
    if (ch == '\n' || ch == EOF)
      break;

    if (state == 0) {
      if (ch == '[')
        state++;
    }
    else if (state == 1) {
      if (ch == ':') {
        state_count[0] = 2;
        state_count[1] = -2;
        state_count[2] = -1;
        state++;
      }
    }
    else {
      if (ch == '|')
        state_count[0]++;
      else if (ch == ':') {
        state_count[1] = state_count[0] + 1;
      }
      else if (ch == ']') {
        state_count[2] = state_count[1] + 1;
      }
    }
  }
  printf("%d\n", state_count[2]);

  return 0;
}
