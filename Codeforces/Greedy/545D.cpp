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

	int n, t, i;
	vector<int> arr;

	cin >> n;
	for(i=0; i<n; ++i){
		cin >> t;
		arr.pb(t);
	}
	sort(all(arr));

	long int sum = 0;
	int count = 0;
	for(i=0; i<n; ++i){
		if(sum <= arr[i]){
			count++;
			sum += arr[i];
		}
	}
	cout << count << endl;

	return 0;
}
