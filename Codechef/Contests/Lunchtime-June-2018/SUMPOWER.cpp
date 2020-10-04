#include <iostream>
#include <vector>
#include <string>

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

	int T;
	int N, K;
	string in_str;
	int i, j, k;
	int len;
	llong sum;
	llong temp;

	cin >> T;
	while(T--){
		cin >> N >> K;
		cin >> in_str;

		vector<short> arr(N, false);
		for(i=1; i<N; ++i){
			if(in_str[i] != in_str[i-1])
				arr[i] = 1;
		}

		sum = 0;
		for(i=1; i<=K; ++i){
			sum += arr[i];
		}

		i = 2;
		j = K+1;
		temp = sum;
		for(; j<N; ++i, ++j){
			temp = temp - arr[i-1] + arr[j];
			sum += temp;
			// sum = sum - arr[i-1] + arr[j];
		}

		cout << sum << endl;
	}

	return 0;
}
