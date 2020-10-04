#include <iostream>

using namespace std;

int reduceNumber(const char *b, int a);
int gcd(int a, int b);

int main(){
  int t;
  scanf("%d", &t);

  int a, num;
  char b[255];

  while(t--){
    scanf("%d %s", &a, b);

    if (a == 0){
      printf("%s\n", b);
      continue;
    }

    num = reduceNumber(b, a);
    if (num == 0){
      printf("%d\n", a);
      continue;
    }

    printf("%d\n", gcd(a, num));
  }

  return 0;
}

int reduceNumber(const char *b, int a){
  int mod = 0;

  for(int i=0; b[i]; ++i){
    mod = (mod*10 + b[i] - '0')%a;
  }

  return mod;
}

int gcd(int a, int b){
  if (b > a)
    return gcd(b, a);

  if (b == 0)
    return a;

  return gcd(b, a%b);
}
