#include <iostream>
#include <vector>
#include <algorithm>

#define M 1000000007

using namespace std;

unsigned long long int SUMQ(int p, int q, int r);

int main()
{
	std::ios::sync_with_stdio(false);

	short test;
	int p, q, r;

	cin >> test;

	while(test--)
	{
		cin >> p >> q >> r;
		cout << SUMQ(p,q,r)%M << endl;
	}

	return 0;
}

unsigned long long int SUMQ(int p, int q, int r)
{
	std::ios::sync_with_stdio(false);

	int i, j, k;
	int temp;
	unsigned long long int sum=0;
	unsigned long long int t1, t2, t3, t4, t5;
	vector<int> A;
	vector<int> B;
	vector<int> C;

	for(i=0; i<p; ++i)
	{
		cin >> temp;
		A.push_back(temp);
	}
	for(i=0; i<q; ++i)
	{
		cin >> temp;
		B.push_back(temp);
	}
	for(i=0; i<r; ++i)
	{
		cin >> temp;
		C.push_back(temp);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	for(i=0; i<q; ++i)
	{
		for(j=0; j<p; j++)
		{
			if(A[j]>B[i])
				break;
			for(k=0; k<r; ++k)
			{
				if(C[k]>B[i])
					break;

				t1 = sum%M;
				t2 = A[j]%M;
				t3 = B[i]%M;
				t4 = (t2+t3)%M;
				t2 = C[k]%M;
				t3 = B[i]%M;
				t5 = (t2+t3)%M;
				t2 = (t4*t5)%M;
				sum = (t1+t2)%M;
			}
		}
	}
	return sum;
}
