#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, i, a, k;
	cin >> t;

	while(t--){
		cin >> n >> k;

		vector<int> motu;
		vector<int> tomu;
		int sumMotu = 0;
		int sumTomu = 0;

		for(i=0; i<n; ++i){
			cin >> a;
			if(i%2 == 0){
				sumMotu += a;
				motu.push_back(a);
			}
			else{
				sumTomu += a;
				tomu.push_back(a);
			}
		}

		if(sumTomu > sumMotu){
			cout << "YES" << endl;
		}
		else{
			sort(motu.begin(), motu.end());
			sort(tomu.begin(), tomu.end());

			int l = motu.size()-1;
			int f = 0;
			for(i=0; i<k;){
				if((f > tomu.size()-1) || (l < 0))
					break;
				if(motu[l] > tomu[f]){
					sumMotu = sumMotu - motu[l] + tomu[f];
					sumTomu = sumTomu - tomu[f] + motu[l];
					swap(motu[l], tomu[f]);
					f++;
					i++;
				}
				else
					l--;
			}

			if(sumTomu > sumMotu){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
