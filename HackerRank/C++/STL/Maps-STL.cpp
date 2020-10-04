#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	map<string, int> student;
	int Q, Y, i;
	short type;
	string X;
	map<string,int>::iterator itr;

	cin >> Q;

	for(i=0; i<Q; ++i)
	{
		cin >> type;

		switch(type)
		{
			case 1	:	cin >> X >> Y;
						// cout << X << '\n';
						itr = student.find(X);
						if(itr != student.end() )
						{
							Y += itr->second;
							student.erase(X);
							// student.insert(make_pair(X,(itr->second)+Y) );
							student.insert(make_pair(X,Y));
						}
						else
							student.insert(make_pair(X,Y));
						// student.insert(make_pair(X,Y));
						break;

			case 2	:	cin >> X;
						student.erase(X);
						break;

			case 3	:	cin >> X;
						itr = student.find(X);
						if(itr != student.end() )
							cout << itr->second << '\n';
						else
							cout << "0\n";
						break;
		}
	}

	return 0;
}