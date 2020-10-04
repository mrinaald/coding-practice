#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int pushButtons(vector<vector<int> > &arr, int n, int m, int times);
int min(const int a, const int b){
	return (a<b)?a:b;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n, m, x, i;
	int steps = 0;
	bool flag = false;
	queue<int> tree;
	vector<int> hasOcc(20000, false);

	cin >> n >> m;
	tree.push(n);

	while((!tree.empty()) && (flag==false)){
		int n = tree.size();
		for(i=0; i<n; ++i){
			x = tree.front();
			tree.pop();
			if(x==m)
				flag=true;
			if(x<1)
				continue;
			else if(x > m){
				if(hasOcc[x-1]==false){
					tree.push(x-1);
					hasOcc[x-1] = true;
				}
			}
			else{
				if(hasOcc[x*2]==false){
					tree.push(x*2);
					hasOcc[x*2] = true;
				}
				if(hasOcc[x-1]==false){
					tree.push(x-1);
					hasOcc[x-1] = true;
				}
			}
		}
		if(flag==false)
			steps++;
	}

	cout << steps << endl;

	return 0;
}
