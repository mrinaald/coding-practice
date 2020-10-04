#include <iostream>
#include <stack>

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
  char str[100005];
  scanf("%s", str);

  int len;
  for (len=0; str[len]; ++len);

  stack<char> stk;
  bool first_player_wins = false;

  for (int i=0; i<len; ++i) {
    if (stk.empty()) {
      stk.push(str[i]);
    }
    else if (stk.top() == str[i]) {
      stk.pop();
      first_player_wins = !first_player_wins;
    }
    else {
      stk.push(str[i]);
    }
  }

  if (first_player_wins) {
    printf("YES\n");
  }
  else {
    printf("NO\n");
  }

  return 0;
}
