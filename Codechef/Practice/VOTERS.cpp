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

int main(){
  // std::ios::sync_with_stdio(false);

  int n1, n2, n3;
  int i, j, k;

  // cin >> n1 >> n2 >> n3;
  scanf("%d", &n1);
  scanf("%d", &n2);
  scanf("%d", &n3);
  // printf("%d %d %d\n", n1, n2, n3);

  vector<llong> l1(n1);
  for(i=0; i<n1; ++i)
    scanf("%lld", &(l1[i]));
    // cin >> l1[i];

  vector<llong> l2(n2);
  for(i=0; i<n2; ++i)
    scanf("%lld", &(l2[i]));
    // cin >> l2[i];

  vector<llong> l3(n3);
  for(i=0; i<n3; ++i)
    scanf("%lld", &(l3[i]));
    // cin >> l3[i];

  // printf("%d %d %d %lld %lld %lld\n", n1, n2, n3, l1[n1-1], l2[n2-1], l3[n3-1]);
  vector<llong> ans;
  int flag = 0;
  i = j = k = 0;
  int minid;
  int nextmin;

  while(flag < 2){
    if(i == n1){
      i++;
      flag++;
      continue;
    }
    if(j == n2){
      j++;
      flag++;
      continue;
    }
    if(k == n3){
      k++;
      flag++;
      continue;
    }

    if (i > n1){
      if (l2[j] == l3[k]){
        ans.pb(l2[j]);
        j++; k++;
      }
      else if(min(l2[j], l3[k]) == l2[j]){
        while(j<n2 && l2[j]<l3[k])
          j++;
      }
      else{
        while(k<n3 && l3[k]<l2[j])
          k++;
      }
    }
    else if (j > n2){
      if (l1[i] == l3[k]){
        ans.pb(l1[i]);
        i++; k++;
      }
      else if (min(l1[i], l3[k]) == l1[i]){
        while(i<n1 && l1[i]<l3[k])
          i++;
      }
      else{
        while(k<n3 && l3[k]<l1[i])
          k++;
      }
    }
    else if (k > n3){
      if (l1[i] == l2[j]){
        ans.pb(l1[i]);
        i++; j++;
      }
      else if (min(l1[i], l2[j]) == l1[i]){
        while(i<n1 && l1[i]<l2[j])
          i++;
      }
      else{
        while(j<n2 && l2[j]<l1[i])
          j++;
      }
    }
    else{
      minid = min(min(l1[i], l2[j]), l3[k]);

      if (minid==l1[i] && minid==l2[j] && minid==l3[k]){
        ans.pb(l1[i]);
        i++; j++; k++;
      }
      else if (minid==l1[i] && minid==l2[j]){
        ans.pb(l1[i]);
        i++; j++;
      }
      else if (minid==l2[j] && minid==l3[k]){
        ans.pb(l2[j]);
        j++; k++;
      }
      else if (minid==l1[i] && minid==l3[k]){
        ans.pb(l1[i]);
        i++; k++;
      }
      else if (minid == l1[i]){
        nextmin = min(l2[j], l3[k]);
        while(i<n1 && l1[i]<nextmin)
          i++;
      }
      else if (minid == l2[j]){
        nextmin = min(l1[i], l3[k]);
        while(j<n2 && l2[j]<nextmin)
          j++;
      }
      else if (minid == l3[k]){
        nextmin = min(l1[i], l2[j]);
        while(k<n3 && l3[k]<nextmin)
          k++;
      }
    }
  }

  k = ans.size();
  printf("%d\n", k);
  for(i=0; i<k; ++i)
    printf("%lld\n", ans[i]);

  return 0;
}
