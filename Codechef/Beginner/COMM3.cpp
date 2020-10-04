#include <iostream>
#include <math.h>

using namespace std;

#define N 3

struct Pos
{
	int x;
	int y;
};

bool commPossible( Pos *tr, short r);
bool distance(Pos *tr, short i, short r);

int main()
{
	std::ios::sync_with_stdio(false);

	short T, R, i;
	Pos transRec[3];

	cin >> T;

	for(i=0; i<T; ++i)
	{
		cin >> R;

		for(short j=0; j<N; ++j)
			cin >> (transRec[j]).x >> (transRec[j]).y;

		if(commPossible(transRec, R))
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}

bool commPossible( Pos *tr, short r)
{
	bool flag = true;

	for( short i=0; i<N; ++i)
	{
		if(distance(tr, i, r))
			continue;
		else
		{
			flag = false;
			break;
		}
	}

	return flag;
}

bool distance(Pos *tr, short i, short r)
{
	bool flag = true;
	float distance;
	for( short j=0; j<N; ++j)
	{
		if(j==i)
			continue;
		else
		{
			distance = sqrt( ((tr[i]).x - (tr[j]).x)*((tr[i]).x - (tr[j]).x) + ((tr[i]).y - (tr[j]).y)*((tr[i]).y - (tr[j]).y));
			if( distance > r)
			{
				flag = false;
				continue;
			}
			else
			{
				flag = true;
				break;
			}
		}
	}

	return flag;
}