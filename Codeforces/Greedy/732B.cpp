#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, k, i, a;
	cin >> n >> k;

	vector<int> givenSeq;

	for(i=0; i<n; ++i){
		cin >> a;
		givenSeq.pb(a);
	}

	int count = 0;
	n--;

	for(i=0; i<n; ++i){
		if((givenSeq[i]+givenSeq[i+1])<k){
			a = givenSeq[i+1];
			givenSeq[i+1] = k - givenSeq[i];
			count += givenSeq[i+1]-a;
		}
	}

	cout << count << endl;
	for(i=0; i<=n; ++i){
		cout << givenSeq[i] << ' ';
	}
	cout << endl;

	return 0;
}
