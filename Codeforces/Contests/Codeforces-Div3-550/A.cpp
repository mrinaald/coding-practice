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

string isDiverse(string &str);

int main(){
  std::ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int i;
  string str;

  FOR(i, 0, n, 1){
    cin >> str;

    cout << isDiverse(str) << endl;
  }

  return 0;
}

string isDiverse(string &str){
  int len = str.length();
  string yes = "Yes";
  string no = "No";

  if (len == 1)
    return yes;

  vector<bool> table(26, false);
  int ch;

  int i;
  FOR(i, 0, len, 1){
    ch = str[i] - 'a';
    if (table[ch] == true)
      return no;
    table[ch] = true;
  }

  i = 0;
  while(i<26 && table[i]==false)
    i++;

  while(i<26 && table[i]==true)
    i++;

  while(i<26 && table[i]==false)
    i++;

  if (i==26)
    return yes;
  else
    return no;
}
