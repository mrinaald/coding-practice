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

int main(){
  // std::ios::sync_with_stdio(false);
  string in_str;
  size_t pos, len;
  bool is_real_fancy;

  int t;
  scanf("%d\n", &t);

  while (t--) {
    getline(cin, in_str);
    len = in_str.length();

    is_real_fancy = false;
    pos = in_str.find("not");

    while (pos != string::npos) {
      if ((!pos) && (pos+3 == len)) {
        // in_str == "not"
        is_real_fancy = true;
        break;
      }
      else if ((!pos)) {
        // in_str has "not" in beginning
        if (in_str[pos+3] == ' ') {
          is_real_fancy = true;
          break;
        }
      }
      else if (pos+3 == len) {
        // in_str has "not" in end
        if (in_str[pos-1] == ' ') {
          is_real_fancy = true;
          break;
        }
      }
      else {
        // in_str has "not" in middle
        if ((in_str[pos-1] == ' ') && (in_str[pos+3] == ' ')) {
          is_real_fancy = true;
          break;
        }
      }
      pos = in_str.find("not", pos+1);
    }

    printf( (is_real_fancy)?"Real Fancy\n":"regularly fancy\n" );
  }

  return 0;
}
