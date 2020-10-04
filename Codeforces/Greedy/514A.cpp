#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	unsigned long long int x;
	cin >> x;

	vector<short> num;
	unsigned long long int temp = x;
	while(temp>0){
		num.pb(temp%10);
		temp /= 10;
	}

	int i;
	int n = num.size()-1;
	for(i=0; i<(n); ++i){
		if(num[i] > 4)
			num[i] = 9-num[i];
	}
	if((num[n]!=9) && (num[i] > 4)){
		num[n] = 9-num[n];
	}

	for(i=n; i>=0; --i){
		cout << num[i];
	}
	cout << endl;

	return 0;
}
