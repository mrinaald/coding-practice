#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

#define R_INDEX 0
#define G_INDEX 1
#define B_INDEX 2
#define TOTAL_INDEX 3

vector<vector<int>> perms{
  vector<int>{R_INDEX, G_INDEX, B_INDEX},
  vector<int>{R_INDEX, B_INDEX, G_INDEX},
  vector<int>{G_INDEX, R_INDEX, B_INDEX},
  vector<int>{G_INDEX, B_INDEX, R_INDEX},
  vector<int>{B_INDEX, R_INDEX, G_INDEX},
  vector<int>{B_INDEX, G_INDEX, R_INDEX},
};

vector<string> colors{"R", "G", "B"};

int get_changes(const vector<vector<int>> &counts_table,
                const vector<int> &permutation);

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string garland;
  cin >> garland;

  int i;
  vector<vector<int>> counts_table(3, vector<int>(4, 0));

  for (i=0; i<n; ++i) {
    if (garland[i] == 'R') {
      counts_table[i % 3][R_INDEX]++;
    }
    if (garland[i] == 'G') {
      counts_table[i % 3][G_INDEX]++;
    }
    if (garland[i] == 'B') {
      counts_table[i % 3][B_INDEX]++;
    }
    counts_table[i % 3][TOTAL_INDEX]++;
  }

  int changes = 0;
  int min_changes = n;
  string seq;

  for (i=0; i<perms.size(); ++i) {
    changes = get_changes(counts_table, perms[i]);
    if (changes < min_changes) {
      min_changes = changes;
      seq = colors[perms[i][0]] + colors[perms[i][1]] + colors[perms[i][2]];
    }
  }

  int m;
  for (i=0; i<n; ++i) {
    m = i % 3;
    if (garland[i] != seq[m]) {
      garland[i] = seq[m];
    }
  }

  cout << min_changes << "\n" << garland << endl;

  return 0;
}

int get_changes(const vector<vector<int>> &counts_table,
                const vector<int> &permutation) {
  int c0 = permutation[0];
  int c1 = permutation[1];
  int c2 = permutation[2];

  int changes = 0;
  changes += (counts_table[0][TOTAL_INDEX] - counts_table[0][c0]);

  if (counts_table[1][TOTAL_INDEX] > 0)
    changes += (counts_table[1][TOTAL_INDEX] - counts_table[1][c1]);

  if (counts_table[2][TOTAL_INDEX] > 0) {
    changes += (counts_table[2][TOTAL_INDEX] - counts_table[2][c2]);
  }

  return changes;
}
