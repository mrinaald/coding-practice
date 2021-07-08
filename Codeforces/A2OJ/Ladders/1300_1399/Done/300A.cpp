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

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, i;
  cin >> n;

  vector<int> neg_arr;
  vector<int> pos_arr;
  int zeros = 0;
  int x;
  for (i=0; i<n; ++i) {
    cin >> x;
    if (x < 0) {
      neg_arr.pb(x);
    } else if (x > 0) {
      pos_arr.pb(x);
    } else {
      zeros++;
    }
  }

  vector<int> neg_set;
  vector<int> zero_set(zeros, 0);
  vector<int> pos_set;

  neg_set.pb(neg_arr[0]);   // Since the solution exists, there will be atleast one negative elemnt
  x = neg_arr.size() - 1;   // Number of negative ints left
  if (x & 1) {
    zero_set.pb(neg_arr[1]);
    x--;
  }

  if (x > 0) {
    pos_set.insert(pos_set.begin(), neg_arr.begin()+(neg_arr.size() - x), neg_arr.end());
  }
  if (pos_arr.size() > 0) {
    pos_set.insert(pos_set.end(), pos_arr.begin(), pos_arr.end());
  }

  // Printing neg set
  cout << neg_set.size();
  for (i=0; i<neg_set.size(); ++i) {
    cout << " " << neg_set[i];
  }
  cout << "\n";

  // Printing pos set
  cout << pos_set.size();
  for (i=0; i<pos_set.size(); ++i) {
    cout << " " << pos_set[i];
  }
  cout << "\n";

  // Printing zeros set
  cout << zero_set.size();
  for (i=0; i<zero_set.size(); ++i) {
    cout << " " << zero_set[i];
  }
  cout << "\n";


  cout << std::flush;
  return 0;
}
