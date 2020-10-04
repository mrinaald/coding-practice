#include <iostream>
#include <vector>

using namespace std;

int abs(int x) {
  return x >= 0 ? x : -x;
}

int get_cost(int a, int t) {
  if (a == t) return 0;
  else if (a > t) return a - t - 1;
  else return t - 1 - a;
}

int main() {
  // your code goes here
  int n;
  scanf("%d", &n);

  int i, a;
  vector<int> arr(101, 0);
  vector<int> sorted_arr(n);
  int min = 200;
  int max = -1;

  for (i=0; i<n; ++i) {
    scanf("%d", &a);
    arr[a]++;

    if (a < min) min = a;
    if (a > max) max = a;
  }

  i = 0;
  for (a=min; a<=max; ++a) {
    while (arr[a] > 0) {
      sorted_arr[i++] = a;
      arr[a]--;
    }
  }

  int mid;
  if (n % 2 == 0) {
    mid = (sorted_arr[(n-1)/2] + sorted_arr[n/2]) / 2;
  }
  else {
    mid = sorted_arr[n/2];
  }

  int prev_cost = 0;
  int curr_cost = 0;
  int next_cost = 0;

  for (i=0; i<n; ++i) {
    prev_cost += get_cost(sorted_arr[i], mid - 1);
    curr_cost += get_cost(sorted_arr[i], mid);
    next_cost += get_cost(sorted_arr[i], mid + 1);
  }

  if ((prev_cost < curr_cost) && (prev_cost < next_cost)) {
    printf("%d %d\n", mid-1, prev_cost);
  }
  else if (curr_cost < next_cost) {
    printf("%d %d\n", mid, curr_cost);
  }
  else {
    printf("%d %d\n", mid+1, next_cost);
  }

  return 0;
}
