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

struct Frog {
  int weight;
  int index;
  int jump_len;
};

bool compare_frogs(const Frog& lhs, const Frog& rhs) {
  return lhs.weight < rhs.weight;
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n, i;
  int last_pos;
  int k, num_kicks;

  cin >> t;
  while (t--) {
    cin >> n;

    vector<Frog> frogs(n);

    for (i=0; i<n; ++i) {
      cin >> frogs[i].weight;
      frogs[i].index = i;
    }

    for (i=0; i<n; ++i)
      cin >> frogs[i].jump_len;

    sort(all(frogs), compare_frogs);

    // for (i=0; i<n; ++i) {
    //   cout << "(" << frogs[i].weight << ", "
    //        << frogs[i].index << ", "
    //        << frogs[i].jump_len << ")\n";
    // }
    // cout << endl;

    last_pos = frogs[0].index;
    num_kicks = 0;
    for (i=1; i<n; ++i) {
      if (frogs[i].index > last_pos) {
        last_pos = frogs[i].index;
        continue;
      }
      k = ((last_pos - frogs[i].index) / frogs[i].jump_len) + 1;
      num_kicks += k;
      frogs[i].index += (k * frogs[i].jump_len);
      last_pos = frogs[i].index;
    }

    cout << num_kicks << "\n";
  }

  cout << std::flush;
  return 0;
}
