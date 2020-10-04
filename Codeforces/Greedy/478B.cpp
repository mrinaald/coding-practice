#include <iostream>
#include <vector>

using namespace std;

unsigned long long int nChoose2(unsigned long long int n);

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mp make_pair

int main(){
	std::ios::sync_with_stdio(false);
	unsigned long long int n, m, k;

	cin >> n >> m;

	unsigned long long int sum = 0;
	unsigned long long int q = n/m;
	unsigned long long int r = n%m;

	sum = nChoose2(q+1)*r;
	sum += nChoose2(q)*(m-r);

	cout << sum << ' ';

	cout << nChoose2(n-m+1) << ' ';

	return 0;
}

unsigned long long int nChoose2(unsigned long long int n){
	unsigned long long int temp;
	if(n<2)
		return 0;
	if(n%2==0){
		temp = n/2;
		return (n-1)*temp;
	}
	else{
		temp = (n-1)/2;
		return temp*n;
	}
}
