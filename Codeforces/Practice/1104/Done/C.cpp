#include <iostream>

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
  char str[1005];
  scanf("%s", str);

  size_t len;
  for (len=0; str[len]; ++len);

  int h_row = 1;
  int h_col[2] = {1, 3};
  int h_col_size = 2;

  int v_row = 3;
  int v_col[4] = {1, 2, 3, 4};
  int v_col_size = 4;

  int h = -1, v = -1;
  for (int i=0; i<len; ++i) {
    switch(str[i]) {
    case '0':
      v++;
      v = v % v_col_size;
      printf("%d %d\n", v_row, v_col[v]);
      break;

    case '1':
      h++;
      h = h % h_col_size;
      printf("%d %d\n", h_row, h_col[h]);
      break;
    }
  }

  return 0;
}
