#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define N 0
#define E 1
#define W 2
#define S 3

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  llong sx, sy, ex, ey;
  cin >> T;
  cin >> sx >> sy >> ex >> ey;

  string winds;
  cin >> winds;

  if ((sx == ex) && (sy == ey)) {
    cout << "0" << endl;
    return 0;
  }

  llong dx = ex - sx;
  llong dy = ey - sy;

  vector<ullong> required_winds(4, 0);    // NEWS
  if (dx > 0) {
    required_winds[E] = dx;
  }
  else if (dx < 0) {
    required_winds[W] = -dx;
  }

  if (dy > 0) {
    required_winds[N] = dy;
  }
  else if (dy < 0) {
    required_winds[S] = -dy;
  }

  ullong total_winds = required_winds[N] + required_winds[E] + required_winds[W] + required_winds[S];
  int t;
  for (t=0; t<T; ++t) {
    if (total_winds == 0)
      break;

    if (winds[t] == 'N') {
      if (required_winds[N] == 0)
        continue;
      required_winds[N]--;
      total_winds--;
    }
    else if (winds[t] == 'E') {
      if (required_winds[E] == 0)
        continue;
      required_winds[E]--;
      total_winds--;
    }
    else if (winds[t] == 'W') {
      if (required_winds[W] == 0)
        continue;
      required_winds[W]--;
      total_winds--;
    }
    else if (winds[t] == 'S') {
      if (required_winds[S] == 0)
        continue;
      required_winds[S]--;
      total_winds--;
    }
  }

  if (total_winds > 0) {
    cout << "-1\n";
  }
  else {
    cout << t << "\n";
  }

  cout << std::flush;
  return 0;
}
