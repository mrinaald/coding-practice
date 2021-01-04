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

#define STATE_START 0
#define STATE_1 1
#define STATE_14 2
#define STATE_144 3
#define STATE_INVALID -1

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string n;
  cin >> n;

  int len = n.length();
  int state = STATE_START;

  for (int i=0; i<len; ++i) {
    switch(n[i]) {
    case '1' :
      switch(state) {
      case STATE_START:
      case STATE_1:
      case STATE_14:
      case STATE_144: state = STATE_1; break;
      default: state = STATE_INVALID; break;
      }
      break;

    case '4':
      switch(state) {
      case STATE_1: state = STATE_14; break;
      case STATE_14: state = STATE_144; break;
      default: state = STATE_INVALID; break;
      }
      break;

    default:
      state = STATE_INVALID;
      break;
    }
    if (state == STATE_INVALID)
      break;
  }

  if (state == STATE_INVALID)
    cout << "NO\n";
  else
    cout << "YES\n";

  cout << std::flush;
  return 0;
}
