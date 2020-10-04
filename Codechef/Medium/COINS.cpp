#include <iostream>
#include <vector>

#define SIZE 1000000

using namespace std;

typedef unsigned long long int ullong;

ullong maxDollars(int n);
ullong max(long int a, long int b);

vector<ullong> A(SIZE+1, -1);

int main()
{
	std::ios::sync_with_stdio(false);

	int n;

	// Initialization of base cases
	for(int i=0; i<=4; ++i){
		A[i] = i;
	}

	while(cin >> n){
		cout << maxDollars(n) << endl;
	}

	return 0;
}

ullong maxDollars(int n){
	if(n>SIZE){
		return max(n, maxDollars(n/2) + maxDollars(n/3) + maxDollars(n/4));
	}
	if(A[n] != -1)
		return A[n];

	A[n] = max(n, maxDollars(n/2) + maxDollars(n/3) + maxDollars(n/4));
	return A[n];
}

ullong max(long int a, long int b){
	return (a>b)?a:b;
}