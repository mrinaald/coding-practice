#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct Point {
  int x = 0;
  int y = 0;
  bool has_left = false;
  bool has_right = false;
  bool has_up = false;
  bool has_down = false;
};

bool sort_x(const Point* lhs, const Point* rhs) {
  if (lhs->x < rhs->x)
    return true;
  else if (lhs->x > rhs->x)
    return false;
  else {
    if (lhs->y <= rhs->y)
      return true;
    else
      return false;
  }
}

bool sort_y(const Point* lhs, const Point* rhs) {
  if (lhs->y < rhs->y)
    return true;
  else if (lhs->y > rhs->y)
    return false;
  else {
    if (lhs->x <= rhs->x)
      return true;
    else
      return false;
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int i, x, y;
  vector<Point*> points(n);
  for (i=0; i<n; ++i) {
    cin >> x >> y;
    points[i] = new Point();
    points[i]->x = x;
    points[i]->y = y;
  }

  if (n < 5) {
    cout << "0" << endl;
    for (i=0; i<n; ++i)
      delete points[i];
    return 0;
  }

  int l, r, j;
  // X-sort
  sort(all(points), sort_x);
  i = 0;
  while (i < n) {
    l = i;
    x = points[i]->x;
    while ((i < n) && (points[i]->x == x))
      ++i;
    r = i-1;
    if (l == r) {
      points[l]->has_up = points[l]->has_down = false;
      continue;
    }

    points[l]->has_down = false;
    points[l]->has_up = true;
    points[r]->has_up = false;
    points[r]->has_down = true;
    for (j=l+1; j<r; ++j) {
      points[j]->has_up = points[j]->has_down = true;
    }
  }

  // Y-sort
  sort(all(points), sort_y);
  i = 0;
  while (i < n) {
    l = i;
    y = points[i]->y;
    while ((i < n) && (points[i]->y == y))
      ++i;
    r = i-1;
    if (l == r) {
      points[l]->has_left = points[l]->has_right = false;
      continue;
    }

    points[l]->has_left = false;
    points[l]->has_right = true;
    points[r]->has_right = false;
    points[r]->has_left = true;
    for (j=l+1; j<r; ++j) {
      points[j]->has_left = points[j]->has_right = true;
    }
  }

  x = 0;
  for (i=0; i<n; ++i) {
    if (points[i]->has_left && points[i]->has_right && points[i]->has_up && points[i]->has_down)
      ++x;
  }

  cout << x << "\n";
  cout << std::flush;

  for (i=0; i<n; ++i)
    delete points[i];
  return 0;
}
