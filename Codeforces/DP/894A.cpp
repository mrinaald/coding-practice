#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

long long int dp(int id, int state);
vector<vector<long long int> > arr;
string str;

int main(){
	std::ios::sync_with_stdio(false);

	char ch;

	ch = getchar();
	while((ch!='\n') && (ch!=EOF)){
		if((ch=='Q') || (ch=='A')){
			str += ch;
		}
		ch = getchar();
	}

	int n = str.length();
	if(n<3){
		cout << 0 << endl;
	}
	else{
		arr.assign(n, vector<long long int>(4,-1));
		cout << dp(n-1, 0) << endl;
	}

	return 0;
}

long long int dp(int id, int state){
	// state 0 : Nothing found
	// state 1 : Q found
	// state 2 : QA found
	// state 3 : QAQ found

	if(state>=3)
		return 1;
	if(id < 0)
		return 0;
	if(arr[id][state] != -1)
		return arr[id][state];

	long long int x;
	switch(state){
		case 0 : if(str[id] == 'Q'){
					 x = dp(id-1, state) + dp(id-1, state+1);
				 }
				 if(str[id] == 'A'){
					 x = dp(id-1, state);
				 }
				 break;
		case 1 : if(str[id] == 'Q'){
					 x = dp(id-1, state);
				 }
				 if(str[id] == 'A'){
					 x = dp(id-1, state) + dp(id-1, state+1);
				 }
				 break;
		case 2 : if(str[id] == 'Q'){
					 x = dp(id-1, state) + dp(id-1, state+1);
				 }
				 if(str[id] == 'A'){
					 x = dp(id-1, state);
				 }
				 break;
	}

	arr[id][state] = x;
	return x;
}
