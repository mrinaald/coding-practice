#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

long long int maxPoints(int i);
vector<long long int> count(100001, 0);
vector<long long int> p(100001, -1);

int main(){
	std::ios::sync_with_stdio(false);

	int n, a, i;
	cin >> n;

	int maxEle = -1;

	for(i=0; i<n; ++i){
		cin >> a;
		count[a]++;
		if(a>maxEle)
			maxEle = a;
	}

	cout << maxPoints(maxEle) << endl;

	return 0;
}

long long int maxPoints(int i){
	if(i < 1)
		return 0;
	if(i==1)
		return count[i];

	if(p[i] == -1)
		p[i] = max(maxPoints(i-1), maxPoints(i-2) + i*count[i]);

	return p[i];
}
