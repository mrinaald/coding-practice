#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define SIZE 1000000

using namespace std;

void computePrimes();
void returnPrimes(int m, int n);
bool checkPrime(int n);

vector<bool> Prime(SIZE+1, true);
vector<int> sortedPrime;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, m, n;

	computePrimes();

	cin >> t;
	while(t--){
		cin >> m >> n;
		returnPrimes(m, n);
		cout << endl;
		// printf("\n");
	}

	return 0;
}

void computePrimes(){
	Prime[0] = Prime[1] = false;
	int i, j, k;

	for(i=2; i<=SIZE; ++i){
		if(Prime[i]==false)
			continue;

		sortedPrime.push_back(i);
		for(j=i*2; j<=SIZE; j += i){
			Prime[j] = false;
		}
	}
}

void returnPrimes(int m, int n){
	int i;
	for(i=m; i<=n; ++i){
		if(i>SIZE){
			if(checkPrime(i)){
				cout << i << endl;
				// printf("%d\n", i);
			}
		}
		else if(Prime[i]){
			cout << i << endl;
			// printf("%d\n", i);
		}
	}
}

bool checkPrime(int n){
	int i;
	double sqrtN = sqrt(n);
	int sortSize = sortedPrime.size();

	for(i=0; (i<=sortSize) && sortedPrime[i]<=sqrtN; ++i){
		if(n%sortedPrime[i] == 0)
			return false;
	}

	return true;
}