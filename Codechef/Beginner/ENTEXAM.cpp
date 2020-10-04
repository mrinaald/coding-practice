#include <iostream>
#include <queue>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;
typedef unsigned int uint;

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, k, e, m;
	int i, j;
	int x;
	llong sum;
	llong temp;

	cin >> t;

	while(t--){
		cin >> n >> k >> e >> m;

		priority_queue<llong> max_heap;

		for(i=1; i<n; ++i){
			sum = 0;
			for(j=0; j<e; ++j){
				cin >> x;
				sum += x;
			}
			max_heap.push(sum);
		}

		sum = 0; 		// sum contains total score of Sergey
		for(i=1; i<e; ++i){
			cin >> x;
			sum += x;
		}

		for(i=0; i<k; ++i){
			temp = max_heap.top();
			max_heap.pop();
		}

		if(sum > temp){
			cout << 0 << endl;
		}
		else if((sum+m) > temp){
			cout << temp-sum+1 << endl;
		}
		else{
			cout << "Impossible" << endl;
		}
	}

	return 0;
}
