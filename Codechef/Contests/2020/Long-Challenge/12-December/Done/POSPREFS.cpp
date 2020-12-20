/* Please see the hint in the end */
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
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, N, K;
  cin >> T;

  int i, f;
  while (T--) {
    cin >> N >> K;

    f = 2 * (N - K);
    if ((f - 1) <= N) {
      for (i=1; i<=N; ++i) {
        if (i & 1) {
          if (i < f) {
            cout << -i << " ";
          }
          else {
            cout << i << " ";
          }
        }
        else {
          cout << i << " ";
        }
      }
    }
    else {
      f = 2 * K;
      for (i=1; i<=N; ++i) {
        if (i & 1) {
          if (i < f) {
            cout << i << " ";
          }
          else {
            cout << -i << " ";
          }
        }
        else {
          cout << -i << " ";
        }
      }
    }

    cout << "\n";
  }

  cout << std::flush;
  return 0;
}


/** Hint:
    If K == 1, then we can keep 1 as positive and rest as negative. (Type-1)
    If K == 2, then we can keep 1,3 as pos and rest as neg. (Type-1)
    If K == 3, then we can keep 1,3,5 as pos and rest as neg. (Type-1)
    ...
    If K == N-3, then we can keep 1,3,5 as neg and rest as pos. (Type-2)
    If K == N-2, then we can keep 1,3 as neg and rest as pos. (Type-2)
    If K == N-1, then we can keep 1 as neg and rest as pos. (Type-2)
    If K == N, then we can keep all as pos.

    We have to see when can we use Type-1 sequence and when can we use Type-2 seq.
 */
