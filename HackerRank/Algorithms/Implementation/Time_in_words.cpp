#include <cmath>
#include <string>
// #include <map>
#include <cstdio>
// #include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void time_in_words(int h, int m);

int main(){
	int h;
	cin >> h;
	int m;
	cin >> m;
	
	time_in_words(h,m);
	
	return 0;
}

void time_in_words(int h, int m)
{
	string hour[] = { ".", "one", "two", "three", "four", "five", "six","seven"
					  , "eight", "nine", "ten", "eleven", "twelve" };

	string min[] = { ".", "one ", "two ", "three ", "four ", "five ", "six ",
					 "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ",
					 "thirteen ", "fourteen ", "quarter ", "sixteen ", 
					 "seventeen ", "eighteen ", "nineteen ", "twenty ", 
					 "twenty one ", "twenty two ", "twenty three ", 
					 "twenty four ", "twenty five ", "twenty six ", 
					 "twenty seven ", "twenty eight ", "twenty nine ", "half "};

	string middle[] = { " o' clock\n", "past ", "to "};

	string mid[] = { "minutes ", "minute "};

	if( m == 0 )
		cout << hour[h] << middle[0];
	else
	{
		if( m<=30 )
		{
			cout << min[m];
		}
		else
		{
			cout << min[60-m];
		}
		if(m==1)
			cout << mid[1];
		else if( (m!=15) && (m!=30) && (m!=45) )
			cout << mid[0];

		if( m<=30 )
		{
			cout << middle[1] << hour[h] << '\n';
		}
		else
		{
			cout << middle[2] << hour[h+1] << '\n';
		}
	}
}