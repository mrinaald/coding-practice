#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

vector<int> subtree_size;
vector<bool> visited;
map<int, vector<int> > edges;
long long int g_count = 0;

int DFS(int v, int parent);

int main(){
	std::ios::sync_with_stdio(false);

	int n, i;
	int u, v;

	cin >> n;

	subtree_size.assign(n+1, 1);
	visited.assign(n+1, false);

	for(i=1; i<n; ++i){
		cin >> u >> v;
		if(edges.find(u) == edges.end())
			edges.insert(mp(u, vector<int>()));
		if(edges.find(v) == edges.end())
			edges.insert(mp(v, vector<int>()));
		edges[u].pb(v);
		edges[v].pb(u);
	}

	if(n%2 != 0){
		cout << -1 << endl;
		return 0;
	}

	visited[0] = true;
	for(i=1; i<=n; ++i){
		if(visited[i] == false)
			u = DFS(i, -1);
	}

	// for(i=1; i<=n; ++i){
	//     cout << i << ": " << subtree_size[i] << endl;
	// }

	cout << g_count << endl;

	return 0;
}

int DFS(int u, int parent){
	visited[u] = true;
	int count = 0;

	int n = edges[u].size();
	int i;
	for(i=0; i<n; ++i){
		if(visited[edges[u][i]] == false)
			count += DFS(edges[u][i], u);
	}

	subtree_size[u] += count;

	if((subtree_size[u]%2==0) && (parent != -1)){
		g_count++;
	}
	return subtree_size[u];
}
