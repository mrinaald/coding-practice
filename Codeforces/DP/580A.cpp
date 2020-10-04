#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

long int nonDecreasingSubsegment(const vector<long int> &arr);

int main(){
	std::ios::sync_with_stdio(false);

	long int n, a, i;
	vector<long int> arr;

	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a;
		arr.pb(a);
	}

	cout << nonDecreasingSubsegment(arr) << endl;

	return 0;
}

long int nonDecreasingSubsegment(const vector<long int> &arr){
	long int n = arr.size();

	vector<long int> countArr(n, 0);
	long int i;

	countArr[0] = 1;
	long int maxCount = -1;
	for(i=1; i<n; ++i){
		if(arr[i] >= arr[i-1]){
			countArr[i] = countArr[i-1] + 1;
		}
		else{
			maxCount = max(maxCount, countArr[i-1]);
			countArr[i] = 1;
		}
	}

	return max(maxCount, countArr[n-1]);
}
