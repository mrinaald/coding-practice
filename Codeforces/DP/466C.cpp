#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;

llong split(int i);
void computeSum();
long long int getSum(int l, int r);

vector<int> arr;
vector<long long int> revSumArr;
vector<llong> numSums;
llong totalSum;
int n;

int main(){
	std::ios::sync_with_stdio(false);

	int i, a;
	llong s;
	llong count = 0;
	cin >> n;

	arr.assign(n, 0);
	for(i=0; i<n; ++i){
		cin >> arr[i];
	}

	revSumArr.assign(n, 0);
	computeSum();

	totalSum = revSumArr[0];
	if(totalSum%3 != 0){
		cout << 0 << endl;
	}
	else{
		numSums.assign(n, -1);
		for(i=0; i<(n-2); ++i){
			s = totalSum - revSumArr[i+1];
			if(s != (totalSum/3))
				continue;

			count += split(i+2);
		}
		cout << count << endl;
	}

	return 0;
}

llong split(int i){
	if(i==n-1)
		return (revSumArr[n-1]==(totalSum/3))?1:0;

	if(numSums[i] != -1)
		return numSums[i];

	numSums[i] = split(i+1) + ((revSumArr[i]==(totalSum/3))?1:0);
	return numSums[i];
	// if(i>j)
	//     return 0;
    //
	// long long int s1, s2, s3;
	// int n = arr.size();
	// s1 = revSumArr[i-1];
	// s3 = revSumArr[n-1] - revSumArr[j];
	// s2 = revSumArr[n-1]-s1-s3;
    //
	// if((s1==s2) && (s1==s3)){
	//     return 1LL + split(i+1, j) + split(i, j-1);
	// }
	// else{
	//     return split(i+1, j) + split(i, j-1);
	// }
}

void computeSum(){
	int n = arr.size();
	revSumArr[n-1] = arr[n-1];
	for(int i=n-2; i>=0; --i){
		revSumArr[i] = revSumArr[i+1] + arr[i];
	}
}

long long int getSum(int l, int r){
	return revSumArr[r] - revSumArr[l];
}
