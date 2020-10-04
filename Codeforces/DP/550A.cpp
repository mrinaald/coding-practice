#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

enum found { NOTHING, AB, BA };

int twoSubStr(int id, found wf);
string str;
vector<int> state;

int main(){
	std::ios_base::sync_with_stdio(false);

	cin >> str;
	int n = str.length();

	if(n<=3){
		cout << "NO" << endl;
	}
	else {
		state.assign(n, -1);
		if(twoSubStr(n-1, NOTHING)==1){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

	return 0;
}

int twoSubStr(int id, found wf){
	if(id<1)
		return 0;

	if(state[id] != -1)
		return state[id];

	if(str[id]=='A' && str[id-1]=='B'){
		if(wf==AB){
			state[id] = 1;
		}
		else{
			state[id] = max(twoSubStr(id-1, wf), twoSubStr(id-2, BA));
		}
	}
	else if(str[id]=='B' && str[id-1]=='A'){
		if(wf==BA){
			state[id] = 1;
		}
		else{
			state[id] = max(twoSubStr(id-1, wf), twoSubStr(id-2, AB));
		}
	}
	else{
		state[id] = twoSubStr(id-1, wf);
	}
	return state[id];
}
