#include <iostream>
#include <vector>
#include <cmath>

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

	int t, n, m;
	int i;
	int count = 0;
	long int ans;

	cin >> t;

	while(t--){
		cin >> n >> m;

		vector<int> arr(n);
		count = 0;

		for(i=0; i<n; ++i){
			cin >> arr[i];
			if(arr[i]%m == 0){
				count++;
			}
		}

		ans = pow(2L, count)-1L;
		cout << ans << endl;
	}

	return 0;
}
