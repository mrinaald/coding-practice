#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define FOR(i,l,h,x) for(i=l; i<h; i+=x)
#define FORE(i,l,h,x) for(i=l; i<=h; i+=x)
#define FORNE(i,l,h,x) for(i=l; i!=h; i+=x)
#define FORIT(i,it) for(i=it.begin(); i!=it.end(); i++)

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int n, m;
vector<int> *true_edge;
vector<int> *back_edge;
int out_count[1000001];
bool visited[1000001];
vector<int> st;
vector<int> top_sort;

void DFS(int v);

int main(){
  std::ios::sync_with_stdio(false);

  cin >> n >> m;

  if(n == 1){
    cout << 1 << endl << 1 << " " << 1 << endl;
    return 0;
  }

  true_edge = new vector<int>()[n];
  back_edge = new vector<int>()[n];

  // true_edge.assign(n+1, vector<int>());
  // back_edge.assign(n+1, vector<int>());
  // visited.assign(n+1, false);
  // out_count.assign(n+1, 0);

  int i;
  int u, v;
  FOR(i, 0, m, 1){
    cin >> u >> v;
    true_edge[u].pb(v);
    back_edge[v].pb(u);
    out_count[u]++;
  }

  FORE(i, 1, n, 1){
    if(visited[i] == false)
      DFS(i);
  }

  st.pb(top_sort[0]);

  return 0;
}

void DFS(int v){
  if(visited[v] == true)
    return;

  visited[v] = true;
  int i;
  int s = true_edge[v].size();
  FOR(i, 0, s, 1){
    if(visited[true_edge[v][i]] == true)
      continue;
    DFS(visited[true_edge[v][i]]);
  }

  top_sort.pb(v);
}
