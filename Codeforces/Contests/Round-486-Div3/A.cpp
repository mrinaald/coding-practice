#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, k, i, a;

	cin >> n >> k;

	vector<bool> already(105, false);
	vector<int> dArr;
	long int distinct = 0;

	for(i=0; i<n; ++i){
		cin >> a;
		if(already[a] == false){
			distinct++;
			dArr.pb(i+1);
			already[a] = true;
		}
	}

	if(distinct < k){
		cout << "NO" << endl;
	}
	else{
		cout << "YES" << endl;
		for(i=0; i<k; ++i){
			cout << dArr[i] << ' ';
		}
		cout << endl;
	}

	return 0;
}
