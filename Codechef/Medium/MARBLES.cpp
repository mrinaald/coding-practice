/*********************************************************************
** Implemented N Choose K using 
*** https://en.wikipedia.org/wiki/Binomial_coefficient#Multiplicative_formula
*********************************************************************/
#include <iostream>

using namespace std;

typedef unsigned long long int ullong;
ullong nChoosek(unsigned int n, unsigned int k);

int main()
{
	std::ios::sync_with_stdio(false);

	int t, n, k;

	cin >> t;
	while(t--){
		cin >> n >> k;
		cout << nChoosek(n-1, k-1) << endl;
		// Why {n-1}C_{k-1}? See the end of file.
	}

	return 0;
}

ullong nChoosek(unsigned int n, unsigned int k){
	ullong prod = 1;

	if((2*k) > n)
		k = n-k;

	unsigned int i;
	for(i=1; i<=k; ++i){
		prod /= i;
	}

	return (ullong)prod;
}


/*********************************************************************
We have to compulsorily choose k marbles, one of each color. So, we are
left to choose n-k marbles.
We find this number by computing the coefficient of x^{n-k} in 
	(1 + x + x^2 + ... + x^{n-k})^k
On simplifying the coefficient, we get {n-1}C_{k-1}
*********************************************************************/