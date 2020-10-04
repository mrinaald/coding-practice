#include <iostream>
#include <vector>

using namespace std;

int main() {
  // your code goes here
  int n, k;
  scanf("%d %d\n", &n, &k);

  int i;
  char ch;
  char curr_ch = '0';
  int counter = 0;
  int level = 0;
  vector<int> count_arr(26, 0);

  for (i=0; i<n; ++i) {
    scanf("%c", &ch);
    if (ch != curr_ch) {
      curr_ch = ch;
      counter = 1;
    }
    else {
      counter++;
    }

    if (counter == k) {
      ch = ch - 'a';
      count_arr[ch]++;
      counter = 0;

      if (count_arr[ch] > level)
        level = count_arr[ch];
    }
  }

  printf("%d\n", level);

  return 0;
}
