#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

long long int swaps(int id, int state);
vector<vector<int> > dp;
string str;
int n;

int main(){
	std::ios::sync_with_stdio(false);

	cin >> str;

	n = str.length();

	dp.assign(n, vector<int>(2, -1));

	cout << swaps(n-1, 0) << endl;

	return 0;
}

long long int swaps(int id, int state){
	if(state>1)
		return 0;
	if(id<0)
		return 0;
	if(dp[id][state] != -1)
		return dp[id][state];

	switch(state){
		case 0 : if(str[id] == '0' || str[id] == '5'){
					 dp[id][state] = min(swaps(id-1, state+1)+(n-1-id), swaps(id-1, state)+1);
				 }
				 else{
					 dp[id][state] = swaps(id-1, state) + (n-1-id);
				 }
				 break;
		case 1 : if(str[id] == '0' || str[id] == '5'){
					 dp[id][state] = min(swaps(id-1, state+1)+(n-1-id), swaps(id-1, state)+1);
				 }
				 else{
					 dp[id][state] = swaps(id-1, state) + (n-1-id);
				 }
				 break;
}
