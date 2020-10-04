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
  int q, n;
  char str[302];
  int len;
  int prev_len;
  int k;
  int i;
  scanf("%d", &q);

  while (q--) {
    scanf("%d", &n);
    scanf("%s", str);

    if (n == 2) {
      if (str[0] < str[1]) {
        printf("YES\n");
        printf("2\n");
        printf("%c %c\n", str[0], str[1]);
      }
      else {
        printf("NO\n");
      }
      continue;
    }

    k = 2;
    prev_len = 1;
    len = 0;
    for (i=1; i < n; ++i) {
      len++;
      if ((len == prev_len + 1) && (len < n - i - 1)) {
        k++;
        prev_len = len;
        len = 0;
      }
    }

    printf("YES\n");
    printf("%d\n", k);
    len = 1;
    k = 1;
    for (i=0; i < n; ++i) {
      if (i == k) {
        printf(" ");
        len++;
        k += len;
        if (len >= (n - k)) {
          k = n;
        }
      }
      printf("%c", str[i]);
    }
    printf("\n");
  }

  return 0;
}
