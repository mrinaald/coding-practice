#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	string num;

	cin >> t;
	while(t--)
	{
		cin >> num;

		int len = num.length();
		bool flag = true;
		
		for(int i=0, j=len-1; i<j; i++,j--)
			if(num[i]!=num[j])
				flag=false;

		cout << ((flag)?"wins\n":"losses\n");
	}
}