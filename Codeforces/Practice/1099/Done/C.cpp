#include <iostream>

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

  char msg[256];
  int msg_len = 0;
  int cane[120];
  int cane_len = 0;
  int flake[120];
  int flake_len = 0;

  char ch;
  scanf("%c", &ch);
  while (ch != '\n') {
    if (ch == '?') {
      cane[cane_len++] = msg_len-1;
    }
    else if (ch == '*') {
      flake[flake_len++] = msg_len-1;
    }
    else {
      msg[msg_len++] = ch;
    }

    scanf("%c", &ch);
  }

  int k;
  scanf("%d", &k);

  if (k > msg_len) {
    if (flake_len > 0) {
      // print 1 possible msg;
      int diff = k - msg_len;

      int i;
      for (i=0; i<flake[0]; ++i) {
        printf("%c", msg[i]);       // not printing flake[0] char
      }
      for (int j=0; j<=diff; ++j) {
        printf("%c", msg[i]);     // printing char b4 flake diff+1 times
      }
      for (i++; i<msg_len; ++i) {
        printf("%c", msg[i]);
      }

      printf("\n");
    }
    else {
      printf("Impossible\n");
    }
  }
  else if (k == msg_len) {
    msg[msg_len++] = '\0';
    printf("%s\n", msg);
  }
  else {
    int min_msg_len = msg_len - cane_len - flake_len;

    if (min_msg_len > k) {
      printf("Impossible\n");
    }
    else {
      // print 1 possible msg;
      int diff = msg_len - k;
      int i;

      if (cane_len >= diff) {
        for (i=0; i<diff; ++i) {
          msg[cane[i]] = '-';
        }
      }
      else {
        for (i=0; i<cane_len; ++i) {
          msg[cane[i]] = '-';
        }

        diff -= cane_len;
        for (i=0; i<diff; ++i) {
          msg[flake[i]] = '-';
        }
      }

      for (i=0; i<msg_len; ++i) {
        if (msg[i] == '-')
          continue;
        printf("%c", msg[i]);
      }
      printf("\n");
    }
  }

  return 0;
}
