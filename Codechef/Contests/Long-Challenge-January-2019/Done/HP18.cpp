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
  int t, n;
  int i;
  int lucky_a, lucky_b;
  int exclusive_a;
  int exclusive_b;
  int common;
  int num;
  int tempa, tempb;
  bool is_bob_winner;

  scanf("%d", &t);

  while (t--) {
    scanf("%d %d %d", &n, &lucky_b, &lucky_a);

    exclusive_a = exclusive_b = common = 0;
    is_bob_winner = false;

    for (i=0; i<n; ++i) {
      scanf("%d", &num);
      tempa = num % lucky_a;
      tempb = num % lucky_b;

      if ((!tempa) && (!tempb))
        common++;
      else if (!tempa)
        exclusive_a++;
      else if (!tempb)
        exclusive_b++;
    }

    if (!common) {
      // no common elements
      if (exclusive_b > exclusive_a)
        is_bob_winner = true;
    }
    else {
      if (exclusive_b >= exclusive_a)
        is_bob_winner = true;
    }

    printf( (is_bob_winner)?"BOB\n":"ALICE\n" );
  }

  return 0;
}
