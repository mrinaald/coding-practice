#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
	std::ios::sync_with_stdio(false);

	int t, n;
	int i;
	llong ans;
	int min_ele;

	cin >> t;

	while(t--){
		cin >> n;

		vector<int> arr(n);

		cin >> arr[0];
		min_ele = arr[0];

		for(i=1; i<n; ++i){
			cin >> arr[i];
			if(arr[i] < min_ele)
				min_ele = arr[i];
		}

		ans = min_ele;
		ans *= (n-1);

		cout << ans << endl;
	}

	return 0;
}
