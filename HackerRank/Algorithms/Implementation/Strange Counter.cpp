#include <iostream>
#include <cstdint>
using namespace std;
int main()
{
	// cout << sizeof(char) << '\n';
	unsigned long long int t;//=100000000000;
	//cout << sizeof(long long int) << '\n';
	cin >> t;
	// cout << t << '\n';
	
	unsigned long long int counter=3;
	unsigned long long int temp=3;
	unsigned long long int time=1;
    
	while(time<t)
	{
		if( (counter+time-1)<t )
		{
			time = time + counter;
			counter *= 2;
			temp = counter;
			// cout << time << ' ';
		}
		else
		{
			temp = temp-(t-time);
			//time += 1;
			break;
		}
	}
	cout << temp << '\n';
	return 0;
}