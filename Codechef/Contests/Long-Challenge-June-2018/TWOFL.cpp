#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef long long int llong;

struct Flower{
	int type;
	int visitingId;

	Flower(){
		type = -1;
		visitingId = -1;
	}
};

vector<vector<Flower> > garden;
map<int, set<int> > neighbours;
map<int, vector<pair<int, int> > > positions;
int n, m;
int primId, secId;
llong g_DFS_ID;
llong g_count;

llong largestRegion();
void DFS(int i, int j);

int main(){
	//std::ios_base::sync_with_stdio(false);

	int i, j, f, k;
	int leftId, upId;

	// cin >> n >> m;
	scanf("%d", &n);
	scanf("%d", &m);

	garden.assign(n, vector<Flower>(m));
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			scanf("%d", &f);
			// cin >> f;
			garden[i][j].type = f;
			leftId = upId = -1;

			if (neighbours.find(f) == neighbours.end()){
				set<int> s;
				neighbours.insert(mp(f, s));
			}

			if (j>0){
				if (f < garden[i][j - 1].type){
					neighbours[f].insert(garden[i][j - 1].type);
				}
				else if (f>garden[i][j - 1].type){
					neighbours[garden[i][j - 1].type].insert(f);
				}
				leftId = garden[i][j - 1].type;
			}
			if (i>0){
				if (f < garden[i - 1][j].type){
					neighbours[f].insert(garden[i - 1][j].type);
				}
				else if (f>garden[i - 1][j].type){
					neighbours[garden[i - 1][j].type].insert(f);
				}
				upId = garden[i-1][j].type;
			}

			if ((leftId != f) && (upId != f)){
				if (positions.find(f) == positions.end()){
					vector<pair<int, int> > p;
					positions.insert(mp(f, p));
				}
				pair<int, int> p(i, j);
				positions[f].pb(p);
			}
		}
	}

	// map<int, vector<pair<int, int> > >::iterator it1 = positions.begin();
	// for (; it1 != positions.end(); ++it1){
	// 	cout << "TYPE: " << it1->first << endl;
	// 	for (int a = 0; a < it1->second.size(); ++a){
	// 		cout << it1->second[a].first << ", " << it1->second[a].second << endl;
	// 	}
	// 	cout << endl;
	// }
	// return 0;

	//cout << neighbours.size() << endl;
	if (neighbours.size() == 1){
		// cout << n*m << endl;
		printf("%d\n", n*m);
		return 0;
	}

	llong dfs_id = 0;
	llong max_count = -1;
	llong count;
	map<int, set<int> >::iterator mit = neighbours.begin();
	for (; mit != neighbours.end(); ++mit){
		set<int> s = mit->second;
		//cout << "Type: " << mit->first << endl;
		set<int>::iterator sit = s.begin();
		for (; sit != s.end(); ++sit){
		//	cout << *sit << ", ";
			// if (mit->first > *sit)
			// 	continue;

			primId = mit->first;
			secId = *sit;
			g_DFS_ID = dfs_id;

			count = largestRegion();
			dfs_id++;
			if (count > max_count)
				max_count = count;
		}
		//cout << endl;
	}

	//cout << max_count << endl;
	printf("%ld\n", max_count);

	return 0;
}

llong largestRegion(){
	llong max_count = -1;
	// for (int i = 0; i < n; ++i){
	// 	for (int j = 0; j < m; ++j){
	// 		if ((garden[i][j].type == primId) || (garden[i][j].type == secId)){
	// 			if (garden[i][j].visitingId == g_DFS_ID)
	// 				continue;
	// 			g_count = 0;
	// 			DFS(i, j);
	// 			if (g_count > max_count)
	// 				max_count = g_count;
	// 		}
	// 	}
	// }

	vector<pair<int, int> > vp = positions[primId];
	int n = vp.size();
	int i, j;
	for (int a = 0; a < n; ++a){
		i = vp[a].first;
		j = vp[a].second;
		if (garden[i][j].visitingId == g_DFS_ID)
			continue;
		g_count = 0;
		DFS(i, j);
		if (g_count > max_count){
			max_count = g_count;
		}
	}

	return max_count;
}

void DFS(int i, int j){
	garden[i][j].visitingId = g_DFS_ID;
	g_count++;

	if (j < (m - 1)){
		if ((garden[i][j + 1].type == primId) || garden[i][j + 1].type == secId){
			if (garden[i][j + 1].visitingId != g_DFS_ID){
				DFS(i, j + 1);
			}
		}
	}

	if (i < (n - 1)){
		if ((garden[i+1][j].type == primId) || garden[i+1][j].type == secId){
			if (garden[i+1][j].visitingId != g_DFS_ID){
				DFS(i+1, j);
			}
		}
	}

	if (j > 0){
		if ((garden[i][j - 1].type == primId) || garden[i][j - 1].type == secId){
			if (garden[i][j - 1].visitingId != g_DFS_ID){
				DFS(i, j - 1);
			}
		}
	}

	if (i > 0){
		if ((garden[i-1][j].type == primId) || garden[i-1][j].type == secId){
			if (garden[i-1][j].visitingId != g_DFS_ID){
				DFS(i-1, j);
			}
		}
	}

	return;
}
