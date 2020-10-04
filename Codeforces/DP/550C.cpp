#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int dp(int id, int state, int num);

string str;
vector<int> ans;
// bool found = false;

int main(){
	std::ios::sync_with_stdio(false);

	int n, i, x;
	// bool found = false;
	int found = -1;

	cin >> str;

	n = str.length();
	ans.assign(n, -1);

	found = dp(n-1, 0, 0);

	if(found!=-100){
		cout << "YES" << endl;
		for(i=0; i<=found; ++i){
			cout << str[i];
		}
		for(i=0; i<n; ++i){
			if(ans[i] != -1)
				cout << ans[i];
		}
		cout << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}

int dp(int id, int state, int num){
	// state 0 : start state
	// state 1 : 1 digit number
	// state 2 : 2 digit number
	// state 3 : 3 digit number
	// state 4 : found the number

	if((id<0) || (state==3)){
		if(state != 0){
			if(num%8==0){
				return id;
			}
		}
		return -100;
	}

	int x = str[id] - '0';
	switch(state){
		case 1 : x = (x*10) + num;
				 break;
		case 2 : x = (x*100) + num;
				 break;
	}
	int f = dp(id-1, state+1, x);
	if(f!=-100){
		ans[id] = str[id] - '0';
		return f;
	}
	else{
		ans[id] = -1;
		f = dp(id-1, state, num);
		return f;
	}
}
