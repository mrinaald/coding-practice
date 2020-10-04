#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;

int main(){
	std::ios::sync_with_stdio(false);

	int n, i, j;

	cin >> n;

	vector<int> arr(n, 0);
	map<int, int> m;
	int max_count = 1;

	for(i=0; i<n; ++i){
		cin >> arr[i];
		if(m.find(arr[i]) == m.end()){
			m.insert(mp(arr[i], 1));
		}
		else{
			m[arr[i]] += 1;
			if(m[arr[i]] > max_count)
				max_count = m[arr[i]];
		}
	}

	cout << max_count << endl;

	return 0;
}
