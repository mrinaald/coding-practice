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

	int T;
	int i, j, k;
	int l, r;
	int count;

	cin >> T;

	while(T--){
		cin >> l >> r;
		count = 0;
		for(i=l; i<=r; i += 10){
			j = i+10;
			if(j > r)
				break;
			count += 3;
		}
		for(; i<=r; ++i){
			switch(i%10){
				case 2:
				case 3:
				case 9: count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}
