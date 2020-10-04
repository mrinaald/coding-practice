#include <iostream>
#include <string>

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

	string ans;
	int a, b, x;
	int i, j, len;

	cin >> a >> b >> x;

	len = a+b;
	ans = "";

	if(a>b){
		j = -1;
		i = 0;
		while(j < (x-1)){
			if(i%2 == 0){
				ans += "0";
				a--;
			}
			else{
				ans += "1";
				b--;
			}
			j++;
			i++;
		}

		if(i%2 == 0){
			while(b>0){
				ans += "1";
				b--;
			}
			while(a>0){
				ans += "0";
				a--;
			}
		}
		else{
			while(a>0){
				ans += "0";
				a--;
			}
			while(b>0){
				ans += "1";
				b--;
			}
		}
	}
	else{
		j = -1;
		i = 0;
		while(j < (x-1)){
			if(i%2 == 0){
				ans += "1";
				b--;
			}
			else{
				ans += "0";
				a--;
			}
			j++;
			i++;
		}

		if(i%2 == 1){
			while(b>0){
				ans += "1";
				b--;
			}
			while(a>0){
				ans += "0";
				a--;
			}
		}
		else{
			while(a>0){
				ans += "0";
				a--;
			}
			while(b>0){
				ans += "1";
				b--;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
