#include <iostream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int t, b, ans;

	cin >> t;

	for(int i=0; i<t; ++i)
	{
		ans=0;

		cin >> b;

		b -=2;
		b /=2;
		ans = (b*(b+1))/2;

		cout << ans << endl;
	}
	return 0;
}