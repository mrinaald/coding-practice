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

int main(){
	std::ios::sync_with_stdio(false);

	int n, k, i, j;

	cin >> n >> k;

	vector<int> arr(n);

	for(i=0; i<n; ++i){
		cin >> arr[i];
	}

	i = 0;
	j = n-1;

	int count = 0;
	for(; i<n; ++i){
		if(arr[i] <= k)
			count++;
		else
			break;
	}
	for(j=n-1; j>i; --j){
		if(arr[j] <=k)
			count++;
		else
			break;
	}

	cout << count << endl;

	return 0;
}
