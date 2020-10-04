#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 2147483648

unsigned int bitArray(int n, int s, int p, int q)
{
	unsigned int i;
	int num = s%MAX;
	int mid = n/2;
	int size = n-mid;

	vector<unsigned int> firstHalf(size);
	// unsigned int *firstHalf;
	// firstHalf = new unsigned int [n];
	firstHalf[0] = num;
	
	for(i=1; i<mid; ++i)
	{
		num = ( (firstHalf[i-1])*p )%MAX;
		num = (num+q)%MAX;
		firstHalf[i] = num; 
	}
	// for(i=0; i<n; ++i)
	// 	cout << firstHalf[i] << ' ';

	sort(firstHalf.begin(), firstHalf.end());
	
	i=0;
	int result=0;
	while(i<n)
	{
		int j=i+1;
		while( (j<n) && (firstHalf[i]==firstHalf[j]) )
			j++;
		result++;
		i=j;
	}

	vector<int> secondHalf(size);

	num = ( (arr[mid-1])*p )%MAX;
	num = (num+q)%MAX;
	secondHalf[0] = num;
	
	for(i=1; i<size; ++i)
	{
		num = ( (secondHalf[i-1])*p )%MAX;
		num = (num+q)%MAX;
		secondHalf[i] = num; 
	}
	// for(i=0; i<n; ++i)
	// 	cout << secondHalf[i] << ' ';

	sort(secondHalf.begin(), secondHalf.end());
	
	i=0;
	// int result=0;
	while(i<size)
	{
		int j=i+1;
		while( (j<size) && (secondHalf[i]==secondHalf[j]) )
			j++;
		result++;
		i=j;
	}

	return result;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	std::ios::sync_with_stdio(false);
	int N, S, P, Q;
	cin >> N >> S >> P >> Q;
	
	// vector<unsigned int> arr(N);
	// int arr[N];
	
	cout << bitArray(N, S, P, Q) << '\n';
	
	return 0;
}
