#include <iostream>
#include <string>

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

bool findSubsequence(const string &str, const string &substr);

int main(){
  // std::ios::sync_with_stdio(false);

  int t;
  scanf("%d", &t);

  string M, W;

  while(t--){
    cin >> M;
    cin >> W;

    // cout << M << " X " << W << endl;

    if (M.length() < W.length()){
      if (findSubsequence(W, M)){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
    else if (M.length() > W.length()){
      if (findSubsequence(M, W)){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
    else{
      if (M.compare(W) == 0){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
  }

  return 0;
}

bool findSubsequence(const string &str, const string &substr){
  int len1 = str.length();
  int len2 = substr.length();

  int i, j;
  for(i=0, j=0; i<len1 && j<len2; ++i){
    if (str[i] == substr[j])
      j++;
  }

  return j==len2;
}
