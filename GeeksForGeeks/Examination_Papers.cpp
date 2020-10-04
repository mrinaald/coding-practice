// http://www.practice.geeksforgeeks.org/problem-page.php?pid=1091
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long int ullint;

ullint moves(int n, char A, char C, char B);
vector<ullint> array(100,0);

int main()
{
	int T, N;

	cin >> T;

	while(T--)
	{
		cin >> N;
		cout << moves(N, 'a', 'c', 'b') << endl;
	}
	return 0;
}

ullint moves(int n, char A, char C, char B)
{
	if(n==0)
		return 0;

	// ullint k=moves(n-1,A,B,C);
	// k++;
	// k += moves(n-1,B,C,A);
	// return k;

	if(array[n-1]==0)
	{
		array[n-1] = moves(n-1, A,B,C) + 1 + moves(n-1, B,C,A);
	}
	else return array[n-1];
}