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

	int n, m, i, j, k;

	cin >> n >> m;

	int q = n/m;
	vector<int> arr(n);
	vector<int> count(m, 0);
	// vector<int> count2(m, 0);

	for(i=0; i<n; ++i){
		cin >> arr[i];
		count[arr[i]%m] += 1;
	}

	int min_count = 0;
	k = -1;
	int diff;
	for(i=0; i<n; ++i){
		j = arr[i]%m;
		if(count[j] > q){
			// if (k==-1){
			k = (j+1)%m;
			while(count[k] >=q){
				k = (k+1)%m;
			// }
			}
			diff = k - j;
			if (diff<0)
				diff += m;
			min_count += diff;
			arr[i] += diff;
			count[j] -= 1;
			count[k] += 1;
			if(count[k] == q)
				k = -1;
		}
	}

	cout << min_count << endl;
	for(i=0 ;i<n;++i){
		cout << arr[i] << ' ';
	}
	cout << endl;



	return 0;
}
