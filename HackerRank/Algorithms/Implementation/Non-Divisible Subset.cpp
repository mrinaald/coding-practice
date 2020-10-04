#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maxSubSet(vector<unsigned long long int> S, int n, int k);
int max(int a, int b){	return (a>b)?a:b;	}
int main() 
{
	int n, k;
	unsigned long long int num;
	cin >> n >> k;
	vector<unsigned long long int> S;
	
	for(int i=0; i<n; ++i)
	{
		cin >> num;
		S.push_back(num);
	}
	
	cout << maxSubSet(S, n, k) << '\n';
	
	return 0;
}

int maxSubSet(vector<unsigned long long int> S, int n, int k)
{
	vector<int> Sprime(k,0);

	for(int i=0; i<n; ++i)
		Sprime[(S[i])%k]++;

	int max_size=0;
	
	if(k%2)
	{
		if(Sprime[0])
			max_size += 1;
		for(int i=1; i<=(k/2); ++i)
		{
			max_size += max(Sprime[i], Sprime[k-i]);
		}
	}
	else
	{
		if(Sprime[0])
			max_size += 1;
		if(Sprime[k/2])
			max_size += 1;

		for(int i=1; i<(k/2); ++i)
			max_size += max(Sprime[i], Sprime[k-i]);
	}

	return max_size;
}