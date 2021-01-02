/*
 * The constraints of the problem are:
 *    1 second, 256 megabytes, input.txt, output.txt
 * This basically means that we need to read input from the
 * input.txt file, and write our output into the output.txt
 * file
 */
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

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n, m;
  cin >> n >> m;

  /*
   int l;
   string line(n+m, '\0');

   if (m >= n) {
   for (l=0; l<n; ++l) {
   line[2*l] = 'G';
   line[(2*l) + 1] = 'B';
   }
   for (l=2*n; l<(m + n); ++l)
   line[l] = 'G';
   }
   else {
   for (l=0; l<m; ++l) {
   line[2*l] = 'B';
   line[(2*l) + 1] = 'G';
   }
   for (l=2*m; l<(m + n); ++l)
   line[l] = 'B';
   }
   cout << line << "\n";
   */

  /*
    int l;
    string line = "";

    if (m >= n) {
    for (l=0; l<n; ++l) {
    line.append("GB");
    }
    if (m > n)
    line.append(m - n, 'G');
    }
    else {
    for (l=0; l<m; ++l) {
    line.append("BG");
    }
    line.append(n - m, 'B');
    }

    cout << line << "\n";
   */

  int l;
  if (m >= n) {
    for (l=0; l<n; ++l)
      cout << "GB";
    for (; l<m; ++l)
      cout << "G";
  }
  else {
    for (l=0; l<m; ++l)
      cout << "BG";
    for (; l<n; ++l)
      cout << "B";
  }

  cout << "\n";
  cout << std::flush;
  return 0;
}
