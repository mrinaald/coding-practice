#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

struct seg{
	int val;
	int left_size;
	int right_size;

	seg(){
		val = -1;
		left_size = 1;
		right_size = 1;
	}
};

int main(){
	std::ios::sync_with_stdio(false);

	int n, i, a;
	cin >> n;

	vector<seg> arr(n);

	cin >> arr[0].val;
	arr[0].left_size = 1;
	arr[0].right_size = 1;
	for(i=1; i<n; ++i){
		cin >> arr[i].val;
		if(arr[i].val > arr[i-1].val)
			arr[i].left_size = arr[i-1].left_size + 1;
		else
			arr[i].left_size = 1;
	}

	for(i=n-2; i>=0; --i){
		if(arr[i].val < arr[i+1].val)
			arr[i].right_size = arr[i+1].right_size + 1;
		else
			arr[i].right_size = 1;
	}

	// cout << "******\n";
	// for(i=0; i<n; ++i){
	//     cout << arr[i].val << ' ' << arr[i].left_size << ' ' << arr[i].right_size << endl;
	// }
	// cout << "******\n";

	int size = 0;
	int max_len = max(arr[0].right_size, arr[n-1].left_size);

	if(n>1){
		if(arr[0].val >= arr[1].val)
			max_len = max(max_len, arr[1].right_size + 1);
		if((arr[n-2].val >= arr[n-1].val))
			max_len = max(max_len, arr[n-2].left_size + 1);
	}

	for(i=1; i<(n-1); ++i){
		if ((arr[i+1].val - arr[i-1].val) >= 2)
			max_len = max(max_len, arr[i-1].left_size + 1 + arr[i+1].right_size);
		max_len = max(max_len, arr[i-1].left_size + 1);
		max_len = max(max_len, arr[i+1].right_size + 1);
	}

	cout << max_len << endl;

	return 0;
}
