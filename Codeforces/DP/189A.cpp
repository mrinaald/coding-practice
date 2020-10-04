#include <iostream>
#include <vector>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

long long int maxCuts(int n, int a, int b, int c);
long long int maximum(long long int a, long long int b, long long int c){
	return max(a, max(b,c));
}

vector<long long int> cuts(4001, -1);

int main(){
	std::ios::sync_with_stdio(false);

	int n, a, b, c;
	cin >> n >> a >> b >> c;

	cout << maxCuts(n, a, b, c) << endl;

	return 0;
}

long long int maxCuts(int n, int a, int b, int c){
	if(n==0)
		return 0;
	if( (n<a) && (n<b) && (n<c) )
		return -100;
	if(cuts[n] == -1){
		long long int x = maximum(maxCuts(n-a, a, b, c), maxCuts(n-b, a, b, c), maxCuts(n-c, a, b, c));
		if(x<0){
		    cuts[n] = -100;
		}
		else{
		    cuts[n] = x+1;
		}
	}

	return cuts[n];
}
