#include <iostream>
#include <queue>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int get_sum(const int n) {
  return (n * (n+1)) / 2;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  priority_queue<int> max_queue;
  priority_queue<int, vector<int>, greater<int>> min_queue;

  int i, a;
  for (i=0; i<m; ++i) {
    cin >> a;
    max_queue.push(a);
    min_queue.push(a);
  }

  int s = n;
  int min_cost = 0;
  while ((min_queue.size() > 0) && (s > 0)) {
    a = min_queue.top();
    min_queue.pop();

    if (s >= a) {
      min_cost += get_sum(a);
      s -= a;
    }
    else {
      min_cost += (get_sum(a) - get_sum(a - s));
      s = 0;
      break;
    }
  }

  s = n;
  int max_cost = 0;
  while ((max_queue.size() > 0) && (s > 0)) {
    a = max_queue.top();
    max_queue.pop();

    max_cost += a;
    --s;
    if (a > 1)
      max_queue.push(a-1);
  }

  cout << max_cost << " " << min_cost << "\n";
  cout << std::flush;
  return 0;
}
