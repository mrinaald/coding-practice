#include <iostream>
#include <vector>
#include <map>

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

  int n;
  scanf("%d\n", &n);

  map<int, pair<int, int>> paren_map;

  int i, j;
  char ch = 'a';
  for (i=0; i<n; ++i) {
    vector<char> stk;

    while ((scanf("%c", &ch) > 0) && ch != '\n') {
      if (ch == '(')
        stk.pb(ch);
      else if (ch == ')') {
        if (stk.size() > 0) {
          if (stk.back() == '(')
            stk.pop_back();
          else
            stk.pb(ch);
        }
        else {
          stk.pb(ch);
        }
      }
    }

    // Check that stk contains only one type of parenthesis
    if (stk.size() == 0) {
      if (paren_map.find(0) == paren_map.end()) {
        paren_map[0] = make_pair(1, 0);
      }
      else {
        paren_map[0].first += 1;
      }
      continue;
    }

    ch = stk[0];
    for (j=1; j<stk.size(); ++j) {
      if (stk[j] != ch) {
        ch = 'a';
        break;
      }
    }

    // in case stack contains two different types of parenthesis
    if (ch == 'a')
      continue;

    j = stk.size();
    if (paren_map.find(j) == paren_map.end())
      paren_map[j] = make_pair(0, 0);

    if (ch == '(')
      paren_map[j].first += 1;
    else if (ch == ')')
      paren_map[j].second += 1;

  }

  auto it = paren_map.begin();
  ulong count = 0;
  while (it != paren_map.end()) {
    if (it->first == 0) {
      count += it->second.first/2;
    }
    else {
      count += min(it->second.first, it->second.second);
    }
    it++;
  }

  printf("%lu\n", count);

  return 0;
}
