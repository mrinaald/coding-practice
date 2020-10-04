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

vector<bool> present(9);
vector<int> arr(8);
int N, K;
llong g_count = 0;

void func(int i, llong count);

int main(){
	std::ios::sync_with_stdio(false);

	int T, i;

	cin >> T;
	while(T--){
		cin >> N >> K;

		for(i=0; i<N; ++i){
			cin >> arr[i];
			if(arr[i] != 0)
				present[arr[i]] = true;
			else
				present[arr[i]] = false;
		}

		g_count = 0;
		func(0, 0);

		cout << g_count << endl;
	}

	return 0;
}

void func(int id, llong count){
	if(count==K){
		g_count++;
		return;
	}

	if(id==N){
		return;
	}

	if(arr[id] != 0){
		if((id>0) && (arr[id] > arr[id-1])){
			func(id+1, count + 1);
		}
		else{
			func(id+1, count);
		}
		return;
	}

	for(int i=1; i<=N; ++i){
		if(present[i])
			continue;
		arr[id] = i;
		present[i] = true;
		if((id>0) && (arr[id] > arr[id-1])){
			func(id+1, count+1);
		}
		else{
			func(id+1, count);
		}
		present[i] = false;
	}
	arr[id] = 0;
}
