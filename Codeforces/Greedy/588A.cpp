#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, a, p, i;
	vector<int> meat;
	vector<int> price;

	cin >> n;
	for(i=0; i<n; ++i){
		cin >> a >> p;
		meat.pb(a);
		price.pb(p);
	}

	int minPrice = price[0];
	int money = meat[0]*minPrice;

	for(i=1; i<n; ++i){
		if(price[i] < minPrice){
			minPrice = price[i];
		}
		money += meat[i]*minPrice;
	}

	cout << money << endl;

	return 0;
}
