/*************************************************************************
Output Format :

For each test case, print 3 lines containing the formatted A, B, and C, 
respectively. Each A, B, and C must be formatted as follows:

A : Strip its decimal (i.e., truncate it) and print its hexadecimal 
	representation (including the 0x prefix) in lower case letters.
B : Print it to a scale of 2 decimal places, preceded by a + or - sign 
	(indicating if it's positive or negative), right justified, and 
	left-padded with underscores so that the printed result is exactly 
	15 characters wide.
C : Print it to a scale of exactly nine decimal places, expressed in 
	scientific notation using upper case.

*************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	double A, B, C;
	int x;

	// cout << setiosflags(ios::uppercase);
	cin >> T;

	while(T--)
	{
		cin >> A >> B >> C;
		x = (int)A;
		
		cout << hex << showbase << x << '\n';
		cout << resetiosflags(ios_base::hex) << resetiosflags(ios_base::showbase);

		cout << showpos << setw(15) << setprecision(2) << setfill('_') << fixed << B << '\n';
		cout << resetiosflags(ios::showpos) << setw(0);

		cout << scientific << uppercase << setprecision(9) << C << '\n';
		cout << resetiosflags(ios::scientific) << resetiosflags(ios::uppercase) << setprecision(0);
	}

	return 0;
}