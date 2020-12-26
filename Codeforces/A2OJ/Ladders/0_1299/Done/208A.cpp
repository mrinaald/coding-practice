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

  string str;
  cin >> str;

  string str2 ("WUB");

  size_t pos = str.find(str2);
  while (pos != string::npos) {
    str.replace(pos, str2.length(), " ");
    pos = str.find(str2);
  }

  size_t start = str.find_first_not_of(" ");
  size_t end = str.find_last_not_of(" ");

  cout << str.substr(start, end - start + 1) << endl;

  cout << std::flush;
  return 0;
}
