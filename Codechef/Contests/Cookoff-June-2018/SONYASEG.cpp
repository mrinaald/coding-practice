#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

typedef long long int llong;
typedef unsigned long long int ullong;
typedef unsigned long int ulong;

struct Seg{
	int low;
	int high;

	Seg(){
		low = high = 0;
	}

	Seg(int l, int h){
		low = l;
		high = h;
	}
};

int main(){
	std::ios::sync_with_stdio(false);

	int T, N, i, j, k;

	cin >> T;

	while(T--){
		cin >> N;
	}

	return 0;
}
