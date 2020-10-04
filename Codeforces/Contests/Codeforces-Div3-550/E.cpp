#include <iostream>
#include <string>
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

void computeDiff(string &t, string &s, int len, vector<short> &diff, int base);
void computeSum(string &str, vector<short> &divArr, string &median, int base);
void computeDiv(vector<short> &diff, vector<short> &divArr, int base);

int main(){
  std::ios::sync_with_stdio(false);

  int k;
  string s;
  string t;

  cin >> k;
  cin >> s;
  cin >> t;

  vector<short> diff;
  int base = 26;

  computeDiff(t, s, k, diff, base);

  vector<short> divArr;
  computeDiv(diff, divArr, base);

  string median = "";

  computeSum(s, divArr, median, base);

  cout << median << endl;

  return 0;
}

void computeDiff(string &t, string &s, int len, vector<short> &diff, int base){
  bool borrow = false;

  int i;
  int x, y;
  int d;

  for(i=len-1; i>=0; i--){
    x = s[i] - 'a';
    y = t[i] - 'a';

    if (borrow == true)
      y--;

    if (y >= x){
      d = y-x;
      diff.pb(d);
      borrow = false;
    }
    else{
      borrow = true;
      y += base;

      d = y-x;
      diff.pb(d);
    }
  }
}

void computeSum(vector<short> &arr1, vector<short> &arr2, vector<short> &sumArr, int base){
  int n1 = arr1.size();
  int n2 = arr2.size();

  int i = 0;
  int n = min(n1, n2);
  int sum, carry = 0;

  while(i<n){
    sum = arr1[i] + arr2[i] + carry;
    carry = sum/base;
    sum = sum%base;

    sumArr.pb(sum);
  }

  while(i < n1){
    sum = arr1[i] + carry;
    carry = sum/base;
    sum = sum%base;

    sumArr.pb(sum);
  }

  while(i < n2){
    sum = arr2[i] + carry;
    carry = sum/base;
    sum = sum%base;

    sumArr.pb(sum);
  }

  while(carry == 1){
    sum = carry;
    carry = sum/base;
    sum = sum%base;

    sumArr.pb(sum);
  }
}


void computeDiv(vector<short> &diff, vector<short> &divArr, int base){
  int n = diff.size();
  int i;

  divArr.pb(diff[0]/2);
  for(i=1; i<n; ++i){
    if (diff[i]%2 == 0){
      divArr.pb(diff[i]/2);
    }
    else{
      divArr.pb(diff[i]/2);
      divArr[i-1] += base/2;
    }
  }
}


void computeSum(string &str, vector<short> &divArr, string &median, int base){
  int si = str.length()-1;
  int di = 0;
  int ch;
  int carry = 0;
  int n = divArr.size();
  string m = "a";

  while(si >= 0){
    if(di < n){
      ch = str[si] - 'a' + divArr[di] + carry;
      di++;
    }
    else{
      ch = str[si] - 'a' + carry;
    }

    carry = ch/base;
    ch = ch%base;
    m = 'a' + ch;
    median.insert(0, m);
    si--;
  }
}
