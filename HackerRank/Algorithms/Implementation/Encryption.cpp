#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	
	int len = s.length();
	double sroot = sqrt(len);
	int rows = floor(sroot);
	int cols = ceil(sroot); 

	if((rows*cols) < len)
		rows++;

	// cout << rows << ' ' << cols << '\n';
	for(int j=0; j<cols; ++j)
	{
		for(int i=j; i<len; i += cols)
			cout << s[i];
		cout << ' ';
	}
	cout << '\n';
	return 0;
}
