#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

void print_info(vector<vector<int>>& ptol, vector<vector<int>>& ltop) {
  int n = ptol.size();
  int m = ltop.size() - 1;
  int p, l;
  for (p=0; p<n; ++p) {
    cout << p + 1 << " ->";
    for (l=0; l<ptol[p].size(); ++l) {
      cout << " " << ptol[p][l];
    }
    cout << endl;
  }
  cout << "*********************\n";

  for (l=0; l<=m; ++l) {
    cout << l << " ->";
    for (p=0; p<ltop[l].size(); ++p) {
      cout << " " << ltop[l][p] + 1;
    }
    cout << endl;
  }
}

void dfs(vector<vector<int>>& graph, int size, int root, vector<bool>& is_visited) {
  if (is_visited[root] == true) {
    return;
  }

  is_visited[root] = true;
  for (int i=0; i<size; ++i) {
    if (graph[root][i] == 1 && is_visited[i] == false) {
      dfs(graph, size, i, is_visited);
    }
  }
}

int main(){
  // - Use cin, cout for Faster I/O.
  // - Use cout << endl only when you want to flush the output forcefully
  // Ref: https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n, vector<int>(n, 0));
  vector<vector<int>> lang_to_person(m+1, vector<int>());
  int p, l;
  int x, i;
  for (p=0; p<n; ++p) {
    cin >> x;
    if (x == 0) {
      lang_to_person[x].pb(p);
      continue;
    }
    while (x--) {
      cin >> l;
      if (lang_to_person[l].size() > 0) {
        for (i=0; i<lang_to_person[l].size(); ++i) {
          graph[lang_to_person[l][i]][p] = graph[p][lang_to_person[l][i]] = 1;
        }
      }
      lang_to_person[l].pb(p);
    }
  }

  int cnt = 0;
  vector<bool> is_visited(n, false);
  for (i=0; i<n; ++i) {
    if (is_visited[i] == false) {
      dfs(graph, n, i, is_visited);
      cnt++;
    }
  }

  if (cnt == lang_to_person[0].size()) {
    cout << cnt << endl;
  } else {
    cout << cnt - 1 << endl;
  }

  cout << std::flush;
  return 0;
}
