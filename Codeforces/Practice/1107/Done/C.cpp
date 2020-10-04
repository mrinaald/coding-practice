#include <iostream>
#include <queue>
#include <vector>

#define MAX_LEN 200000

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
  int n, k;
  scanf("%d %d", &n, &k);

  int i, a;
  vector<int> damages(n);
  for (i=0; i < n; ++i) {
    scanf("%d", &a);
    damages[i] = a;
  }

  char buttons[MAX_LEN];
  scanf("%s", buttons);

  ullong max_damage = 0;
  ullong temp_damage = 0;

  i = 0;
  int j, x;
  while (i < n) {
    priority_queue<int> pqueue;
    pqueue.push(damages[i]);
    temp_damage = damages[i];

    j = i + 1;
    while ((j < n) && (buttons[j] == buttons[i])) {
      pqueue.push(damages[j]);
      temp_damage += damages[j];
      j++;
    }

    if (j - i <= k) {
      max_damage += temp_damage;
    }
    else {
      for (x = 0; x < k; ++x) {
        max_damage += pqueue.top();
        pqueue.pop();
      }
    }
    i = j;
  }

  printf("%llu\n", max_damage);
  return 0;
}
