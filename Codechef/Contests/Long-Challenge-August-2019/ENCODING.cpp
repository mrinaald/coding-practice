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

#define MAXLEN 100000
#define MOD 1000000007

int nl, nr;
char leftNum[MAXLEN+5];
char rightNum[MAXLEN+5];
char tempNum[MAXLEN+5];

void preprocessNums();
ullong computeFunction();

ullong computeLeftSection(const int index, ullong offset);
ullong computeMiddleSection(const int l, const int r, const int index, ullong offset);
ullong computeRightSection(const int index, ullong offset);
ullong computeOffset(const int high, const int low);

int main(){
  // std::ios::sync_with_stdio(false);

  int t;

  scanf("%d", &t);
  while(t--){
    scanf("%d %s", &nl, leftNum);
    scanf("%d %s", &nr, rightNum);

    preprocessNums();

    printf("%llu\n", computeFunction()%MOD);
  }

  return 0;
}

void preprocessNums(){
  int i, j;
  for (i=0, j=nl-1; i<j; ++i, --j)
    swap(leftNum[i], leftNum[j]);

  for (i=0, j=nr-1; i<j; ++i, --j)
    swap(rightNum[i], rightNum[j]);

  if (nr > nl){
    for (i=nl; i<nr; ++i)
      leftNum[i] = '0';
    leftNum[nr] = '\0';
  }
}

ullong computeOffset(const int high, const int low){
  if (low >= high)
    return 0;

  ullong mod = 0;
  int i = high;

  for (; i>low; --i){
    mod = (mod*10 + tempNum[i] - '0')%MOD;
  }

  while (i >= 0){
    mod = (mod*10 + 0)%MOD;
  }

  return mod;
}

ullong computeFunction(){
  int ans = 0;
  ullong offset = 0;

  int i = nr-1;
  while(i>=1 && rightNum[i]==leftNum[i]){
    tempNum[i] = rightNum[i];
    i--;
  }

  offset = computeOffset(nr-1, i);

  ans = computeMiddleSection(leftNum[i]-'0'+1, rightNum[i]-'0'-1, i, offset) % MOD;

  ans = ((ans) + (computeLeftSection(i, offset)%MOD)) % MOD;

  ans = ((ans) + (computeRightSection(i, offset)%MOD)) % MOD;

  return ans%MOD;
}

ullong computeLeftSection(const int index, ullong offset){
  if (index < 0)
    return 0;

  ullong ans = 0;

  if (!index){
    short i = leftNum[index] - '0';
    ans = ((9-i+1) * offset)%MOD;
    while (i<=9){
      ans = ((ans) + i)%MOD;
      i++;
    }

    return ans;
  }

  int i = index;
  tempNum[index] = leftNum[index];
  while (i>=1 && leftNum[i]=='9'){
    tempNum[i] = '9';
    i--;
  }

  offset = ((offset) + computeOffset(index, i))%MOD;

  return ans;
}

ullong computeMiddleSection(const int low, const int high, const int index, ullong offset);

ullong computeRightSection(const int index, ullong offset);
