#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int a, b;

	cin >> a >> b;

	int c = a-b;

	stringstream ss;
	ss << c;
	string str = ss.str();
	
	if( (str[0]>='0') && (str[0]<='8') )
		str[0]++;
	else if(str[0]=='9')
			str[0]--;

	cout << str << endl;

	return 0;
}