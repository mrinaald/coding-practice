#include <iostream>
#include <vector>

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

bool can_be_zero(const vector<int> &rot, int curr_rot, int id);

int main(){
  // std::ios::sync_with_stdio(false);

  int n;
  scanf("%d", &n);

  vector<int> rot(n);
  int i;
  for (i=0; i<n; ++i) {
    scanf("%d", &(rot[i]));
  }

  if (can_be_zero(rot, 0, 0)) {
    printf("YES\n");
  }
  else {
    printf("NO\n");
  }

  return 0;
}

bool can_be_zero(const vector<int> &rot, int curr_rot, int id) {
  if (id == rot.size()) {
    return (curr_rot % 360) == 0;
  }

  bool r1 = can_be_zero(rot, curr_rot + rot[id], id+1);
  if (r1)
    return r1;
  else
    return can_be_zero(rot, curr_rot - rot[id], id+1);
}
