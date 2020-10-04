#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, m, a, b, i, j;

	cin >> n;

	vector<int> boys(n,0);
	for(i=0; i<n; ++i){
		cin >> boys[i];
	}

	cin >> m;

	vector<int> girls(m, 0);
	for(i=0; i<m; ++i){
		cin >> girls[i];
	}

	sort(all(boys));
	sort(all(girls));

	i = j = 0;
	long long int count = 0;

	while((i<n) && (j<m)){
		if((boys[i]-1) == girls[j]){
			i++;
			j++;
			count++;
		}
		else if(boys[i] == girls[j]){
			i++;
			j++;
			count++;
		}
		else if((boys[i]+1) == girls[j]){
			i++;
			j++;
			count++;
		}
		else if(boys[i] > girls[j]){
			j++;
		}
		else if(boys[i] < girls[j]){
			i++;
		}
	}

	cout << count << endl;

	return 0;
}
