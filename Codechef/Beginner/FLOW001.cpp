#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	short T, i;
	int A, B;

	cin >> T;

	for(i=0; i<T; ++i)
	{
		cin >> A >> B;
		cout << (A+B) << endl;
	}
	return 0;
}