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

int main(){
  std::ios::sync_with_stdio(false);

  int t;
  string str;
  vector<int> table(52, 101);
  int i, id;
  int len;
  int num_jewels;

  cin >> t;
  while(t--){
    num_jewels = 0;

    // input string J
    cin >> str;
    len = str.length();
    for (i=0; i<len; ++i){
      id = (str[i]<='Z')?str[i]-'A':str[i]-'a'+26;
      table[id] = t;
    }

    // input string S
    cin >> str;
    len = str.length();
    for (i=0; i<len; ++i){
      id = (str[i]<='Z')?str[i]-'A':str[i]-'a'+26;
      num_jewels += (table[id]==t)?1:0;
    }

    cout << num_jewels << endl;
  }

  return 0;
}
