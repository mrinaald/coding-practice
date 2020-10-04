#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, a, i;
	int len = 0;
	int maxLen = 0;

	vector<int> arr;

	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a;
		arr.pb(a);
	}

	len = maxLen = 1;
	for(i=1; i<n; ++i){
		if(arr[i] > arr[i-1])
			len++;
		else
			len = 1;
		if(len > maxLen)
			maxLen = len;
	}
	cout << maxLen << endl;

	return 0;
}
