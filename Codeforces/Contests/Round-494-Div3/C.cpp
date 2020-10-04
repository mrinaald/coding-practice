#include <iostream>
#include <vector>
#include <iomanip>

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

	int n, k;
	int i, j;

	cin >> n >> k;

	vector<int> arr(n);
	vector<llong> sumArr(n);
	double sum;
	double avg;
	double max_avg = -1.0;

	cin >> arr[0];
	sumArr[0] = arr[0];

	for(i=1; i<n; ++i){
		cin >> arr[i];
		sumArr[i] = sumArr[i-1] + arr[i];
	}

	for(i=0; i<=(n-k); ++i){
		for(j=i+k-1; j<n; ++j){
			if(i!=0)
				sum = sumArr[j] - sumArr[i-1];
			else
				sum = sumArr[j];
			avg = sum/(j-i+1);
			if(avg > max_avg)
				max_avg = avg;
		}
	}

	cout.precision(15);
	cout << std::fixed << max_avg << endl;

	return 0;
}
