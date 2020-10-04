#include <iostream>
#include <set>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	set<int> A;
	int Q, x, i;
	// enum query={Add, Delete, Find};
	short y;

	cin >> Q;

	for(i=0; i<Q; ++i)
	{
		cin >> y >> x;

		switch(y)
		{
			case 1	:	A.insert(x);
						break;

			case 2	:	A.erase(x);
						// set<int>::iterator itr = A.erase(x);
						break;

			case 3	:	set<int>::iterator itr = A.find(x);
						if( itr != A.end() )
							cout << "Yes\n";
						else
							cout << "No\n";
		}
	}

	return 0;
}