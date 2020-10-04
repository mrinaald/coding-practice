#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, i;

	cin >> n;

	long long int x, h;
	vector<long int> points(n, 0);
	map<long int, long int> m;

	for(i=0; i<n; ++i){
		cin >> x >> h;
		points[i] = x;
		m.insert(mp(x, h));
	}

	long long int sum = 1;
	long long int farthest = points[0];

	for(i=1; i<n; ++i){
		if( (points[i] - m[points[i]]) > farthest ){
			// checking whether we can cut the tree towards left
			sum++;
		}
		else{
			if( i < n-1 ){
				if( (points[i] + m[points[i]]) < points[i+1] ){
					farthest = points[i] + m[points[i]];
					sum++;
				}
			}
			else{
				// cutting the last tree towards right
				sum++;
			}
		}
		if(points[i] > farthest)
			farthest = points[i];
	}

	cout << sum << endl;

	return 0;
}
