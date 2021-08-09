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


int n_Choose_k(int n, int k) {
  if (k == 0 || k == n) {
    return 1;
  }
  if (k == 1 || k == n-1) {
    return n;
  }

  if (k < (n/2)) {
    k = n - k;
  }

  int num = 1;
  int den = 1;
  int i;
  for (i=n; i>(n-k); --i) {
    num *= i;
  }
  for (i=k; i>0; --i) {
    den *= i;
  }

  return num / den;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string orig, received;
  cin >> orig;
  cin >> received;

  int len = orig.length();
  int orig_pos = 0;
  int i;
  for (i=0; i<len; ++i) {
    if (orig[i] == '+') {
      orig_pos++;
    }
    else if (orig[i] == '-') {
      orig_pos--;
    }
  }

  int pos = 0;
  int doubt = 0;
  for (i=0; i<len; ++i) {
    if (received[i] == '+') {
      pos++;
    }
    else if (received[i] == '-') {
      pos--;
    }
    else if (received[i] == '?') {
      doubt++;
    }
  }

  cout.precision(9);
  if (doubt == 0) {
    if (pos == orig_pos) {
      cout << std::fixed << 1.0 << endl;
    }
    else {
      cout << std::fixed << 0.0 << endl;
    }
    return 0;
  }

  vector<int> possibilites;
  for (i=0; i<=doubt; ++i) {
    possibilites.pb(n_Choose_k(doubt, i));
  }

  int total = 0;
  int ans = 0;
  for (i=0; i<possibilites.size(); ++i) {
    if ((pos + doubt) == orig_pos) {
      ans += possibilites[i];
    }
    doubt -= 2;
    total += possibilites[i];
  }

  cout << std::fixed << ((double)ans) / total << "\n";

  cout << std::flush;
  return 0;
}
