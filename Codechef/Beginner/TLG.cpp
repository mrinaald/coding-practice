#include <iostream>
#include <cmath>

#define MAX_RND 10000

using namespace std;

void winner(int p1[], int p2[], int n);

int main()
{
	int N;
	int P1[MAX_RND], P2[MAX_RND];

	cin >> N;

	for( int i=0; i<N; ++i)
	{
		cin >> P1[i];
		cin >> P2[i];
	}

	winner(P1, P2, N);

	return 0;
}

void winner(int p1[], int p2[], int n)
{
	int c_lead=0;						//current lead of each round
	int max_lead=0;
	int sum1=0;
	int sum2=0;
	int win;

	for( int i=0; i<n; ++i)
	{
		sum1 = sum2 = 0;
		for( int j=0; j<=i; ++j)
		{
			sum1 += p1[j];
			sum2 += p2[j];
		}

		c_lead = abs(sum1 - sum2);

		if( c_lead > max_lead )
		{
			max_lead = c_lead;
			win = (sum1 > sum2)?1:2;
		}
	}

	cout << win << " " <<max_lead << endl;
}