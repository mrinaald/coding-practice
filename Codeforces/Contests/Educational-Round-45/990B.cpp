#include <iostream>
#include <vector>
#include <algorithm>

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

	int n, K;
	int i;
	cin >> n >> K;

	vector<int> arr(n, 0);
	for(i=0; i<n; ++i){
		cin >> arr[i];
	}

	sort(all(arr));

	i = 0;
	int j = 1;
	int ate = 0;
	while(j<n && i<n){
		if((arr[j] > arr[i]) && (arr[j] <= (arr[i]+K))){
			ate++;
			// i = j;
			// j++;
			i++;
			continue;
		}
		if((arr[j] == arr[i])){
			j++;
			continue;
		}
		if(arr[j] > (arr[i]+K)){
			i = j;
			j++;
			continue;
		}
	}

	cout << n - ate << endl;

	return 0;
}
