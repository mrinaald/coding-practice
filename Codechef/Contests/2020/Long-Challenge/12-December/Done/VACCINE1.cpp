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

int get_num_days(int total, int per_day) {
  int d = total / per_day;
  if ((d*per_day) != total)
    ++d;
  return d;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int d1, v1, d2, v2, p;
  cin >> d1 >> v1 >> d2 >> v2 >> p;

  if (d1 > d2) {
    swap(d1, d2);
    swap(v1, v2);
  }

  int days = 0;
  days += (min(d1, d2) - 1);    // empty days

  int v, d;
  if (d1 == d2) {
    days += get_num_days(p, v1 + v2);
  }
  else {
    d = get_num_days(p, v1);
    if ((days + d) > d2) {
      days += (d2 - d1);
      v = ((d2 - d1) * v1);
      days += get_num_days(p - v, v1 + v2);
    }
    else {
      days += d;
    }
  }

  cout << days << endl;

  return 0;
}
