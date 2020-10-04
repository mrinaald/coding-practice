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

vector<llong> sumArr;
vector<llong> sortedSum;

int main(){
	std::ios::sync_with_stdio(false);

	int n, m, i;
	int type, l, r;

	cin >> n;

	vector<int> arr(n, 0);
	sumArr.assign(n, 0);
	sortedSum.assign(n, 0);

	cin >> arr[0];
	sumArr[0] = arr[0];
	for(i=1; i<n; ++i){
		cin >> arr[i];
		sumArr[i] = sumArr[i-1] + arr[i];
	}

	sort(all(arr));
	sortedSum[0] = arr[0];
	for(i=1; i<n; ++i){
		sortedSum[i] = sortedSum[i-1] +  arr[i];
	}
	cin >> m;
	while(m--){
		cin >> type >> l >> r;

		switch(type){
			case 1 : if(l==1)
						 cout << sumArr[r-1] << endl;
					 else
					 	cout << sumArr[r-1] - sumArr[l-2] << endl;
					 break;

			case 2 : if(l==1)
						 cout << sortedSum[r-1] << endl;
					 else
					 	cout << sortedSum[r-1] - sortedSum[l-2] << endl;
					 break;
		}
	}

	return 0;
}
