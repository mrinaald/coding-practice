#include <iostream>
#include <string>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);

	int n, i, temp;
	int count=0;

	cin >> n;

	string s;
	cin >> s;

	for(i=0; i<n; ++i){
		if(s[i]=='1')
			count++;
		else if(s[i]=='0')
			count--;
	}

	cout << abs(count) << endl;

	return 0;
}
