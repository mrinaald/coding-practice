#include <iostream>
#include <vector>
#include <map>
#include <iterator>

#define SIZE 1000000

using namespace std;

vector<int> Primes;

void computeSieveOfEratosthens();
map<int, int> computeFactorisation(vector<int> &factors);
int numFactors(map<int, int> &primeFactors);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n;
	int i, temp;

	computeSieveOfEratosthens();

	cin >> t;
	while(t--){
		cin >> n;

		vector<int> factors;
		for(i=0; i<n; ++i){
			cin >> temp;
			factors.push_back(temp);
		}

		map<int, int> primeFactors = computeFactorisation(factors);

		cout << numFactors(primeFactors) << endl;
	}

	return 0;
}

void computeSieveOfEratosthens(){
	vector<bool> SE(SIZE+1, true);
	SE[0] = SE[1] = false;
	int i, j;

	for(i=2; i<=SIZE; ++i){
		if(SE[i] == false)
			continue;

		Primes.push_back(i);
		for(j=2*i; j<= SIZE; j += i){
			SE[j] = false;
		}
	}
}

map<int, int> computeFactorisation(vector<int> &factors){
	map<int, int> primeFactors;
	int num, i, j;

	for(i=0; i<factors.size(); ++i){
		while(factors[i] > 1){
			j = 0;
			for(; Primes[j] <= factors[i]; ++j){
				if((factors[i] % Primes[j]) == 0){
					primeFactors[Primes[j]] += 1;		// the default value of a key is zero
					factors[i] /= Primes[j];
					break;
				}
			}
		}
	}

	return primeFactors;
}

int numFactors(map<int, int> &primeFactors){
	int ans = 1;
	map<int, int>::iterator it;

	for(it=primeFactors.begin(); it!=primeFactors.end(); ++it){
		ans *= ((it->second)+1);
	}
	
	return ans;
}