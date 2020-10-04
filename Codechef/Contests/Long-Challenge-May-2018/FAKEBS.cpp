#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int binSearch(vector<int> &arr, int n, int key);

int main(){
	std::ios::sync_with_stdio(false);

	int t, n, q, i, temp, x;
	int realIndex, numMax, numMin, numSwaps;
	int l, r, m;
	bool flag;

	cin >> t;
	while(t--){
		cin >> n >> q;

		vector<int> arr;
		vector<int> sortedArr;
		map<int,int> pos;
		for(i=0; i<n; ++i){
			cin >> temp;
			arr.pb(temp);
			sortedArr.pb(temp);
			pos.insert(mp(temp, i));
		}

		sort(all(sortedArr));

		while(q--){
			cin >> x;

			realIndex = pos[x];
			numMin = binSearch(sortedArr, n, x);
			numMax = n-1-numMin;
			// cout << "**********\n" << x << endl;
			// cout << "Real Id: " << realIndex << endl;
			// cout << "Num Min: " << numMin << endl;
			// cout << "Num Max: " << numMax << endl;

			l = 0;
			r = n-1;
			flag = true;
			numSwaps = 0;
			while(l<=r){
				m = (l+r)/2;
				// cout << m << " " ;
				if(arr[m] == x){
					break;
				}
				else if(x < arr[m]){
					if(realIndex < m){
						r = m-1;
					}
					else{
						if(numMin){
							numMin--;
							l = m+1;
							numSwaps++;
						}
						else{
							flag = false;
							break;
						}
					}
				}
				else{
					if(realIndex > m){
						l = m+1;
					}
					else{
						if(numMax){
							numMax--;
							r = m-1;
							numSwaps++;
						}
						else{
							flag = false;
							break;
						}
					}
				}
			}

			if(flag){
				cout << numSwaps << endl;
			}
			else{
				cout << -1 << endl;
			}
		}
	}

	return 0;
}

int binSearch(vector<int> &arr, int n, int key){
	int l, r, m;
	l = 0;
	r = n-1;
	while(l<=r){
		m = (l+r)/2;
		if(arr[m] == key)
			return m;
		else if(key < arr[m])
			r = m-1;
		else
			l = m+1;
	}
	return -1;
}
