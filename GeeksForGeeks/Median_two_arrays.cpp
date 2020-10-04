// http://www.practice.geeksforgeeks.org/problem-page.php?pid=240
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int SumMedian(vector<int> A, int leftA, int rightA, vector<int> B,  int leftB, int rightB);

int main()
{
	int T,N;

	cin >> T;

	while(T--)
	{
		cin >> N;
		vector<int> A(N);
		vector<int> B(N);

		for(int i=0; i<N; ++i)
			cin >> A[i];

		for(int i=0; i<N; ++i)
			cin >> B[i];

		cout << SumMedian(A,0,N-1,B,0,N-1) << endl;
	}
}

int SumMedian(vector<int> A, int leftA, int rightA, vector<int> B,  int leftB, int rightB)
{
	if( (rightA-leftA)==1 && (rightB-leftB)==1 )
		return max(A[leftA],B[leftB]) + min(A[rightA],B[rightB]);

	int midA = floor( ((float)(rightA-leftA))/2 ) + leftA;
	int midB = ceil( ((float)(rightB-leftB))/2 ) + leftB;

	if(A[midA]==B[midB])
		return A[midA]*2;
	else if( A[midA]>B[midB] )
		{
			return SumMedian(A,leftA,midA,B,midB,rightB);
		}
		else
			return SumMedian(A,midA,rightA,B,leftB,midB);
}