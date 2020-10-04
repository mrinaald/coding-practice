#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

#define P_INF 2000000
#define N_INF -2000000

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

struct tree_node{
	int lchild;
	int rchild;
	int vmin;
	int vmax;
	int parent;
	bool is_child;
};

int N;
llong tree_sort(vector<tree_node> &t, int root);

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	int i, l, r;

	cin >> t;

	while(t--){
		cin >> N;

		vector<tree_node> tree(N);

		for(i=0; i<N; ++i){
			cin >> l >> r;

			if(l==-1){
				tree[i].is_child = true;
				tree[i].vmin = tree[i].vmax = r;
				tree[i].lchild = tree[i].rchild = -1;
			}
			else{
				tree[i].is_child = false;
				tree[i].lchild = l-1;
				tree[i].rchild = r-1;
				tree[l-1].parent = tree[r-1].parent = i;
				tree[i].vmin = P_INF;
				tree[i].vmax = N_INF;
			}
		}

		cout << tree_sort(tree, 0) << endl;
	}

	return 0;
}

llong tree_sort(vector<tree_node> &t, int root){
	if(t[root].is_child == true)
		return 0;

	int l = t[root].lchild;
	int r = t[root].rchild;

	llong lswaps = tree_sort(t, l);
	if(lswaps == -1)
		return -1;

	llong rswaps = tree_sort(t, r);
	if(rswaps == -1)
		return -1;

	llong ans = 0;

	if((t[l].vmin < t[r].vmin) && (t[l].vmax < t[r].vmin)){
		t[root].vmin = t[l].vmin;
		t[root].vmax = t[r].vmax;
		ans = lswaps + rswaps;
	}
	else if((t[r].vmin < t[l].vmin) && (t[r].vmax < t[l].vmin)){
		t[root].vmin = t[r].vmin;
		t[root].vmax = t[l].vmax;
		ans = lswaps + rswaps + 1;
	}
	else{
		ans = -1;
	}

	return ans;
}
