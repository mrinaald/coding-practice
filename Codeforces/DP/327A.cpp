#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

long int maxOnes(const vector<int> &arr);

int main(){
	std::ios::sync_with_stdio(false);

	int n, a, i;
	vector<int> arr;

	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a;
		arr.pb(a);
	}

	cout << maxOnes(arr) << endl;

	return 0;
}

long int maxOnes(const vector<int> &arr){
	int n = arr.size();
	int i;
	long int maxi = (arr[0]==0)?1:-1;
	int count1 = (arr[0]==1)?1:0;
	vector<long int> cArr(n,0);
	cArr[0] = maxi;

	for(i=1; i<n; ++i){
		if(arr[i] == 1){
			count1++;
			cArr[i] = max((long int)-1, cArr[i-1]-1);
		}
		if(arr[i] == 0){
			cArr[i] = max((long int)1, cArr[i-1]+1);
		}
		if(cArr[i] > maxi){
			maxi = cArr[i];
		}
	}

	return count1 + maxi;
}
