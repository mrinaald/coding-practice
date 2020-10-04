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

	int n, i, temp;

	cin >> n;

	vector<int> box;
	for(i=0; i<n; ++i){
		cin >> temp;
		box.pb(temp);
	}

	sort(all(box));

	for(i=0; i<n; ++i){
		cout << box[i] << ' ';
	}
	cout << endl;

	return 0;
}
