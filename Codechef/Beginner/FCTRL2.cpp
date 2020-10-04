/********************************************************************
// Factorial(MULTiplication) operation for BigInteger is implemented
********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 200						//maximum size of number array

void factorial(short arr[], short size, short num);

int main()
{
	short t, n, arr[MAX], temp, size;

	cin >> t;

	for(short i=0; i<t; ++i)
	{
		cin >> n;
		temp = n;
		
		size = 0;
		while(temp>0)							//loop to store number in array in reverse order
		{
			arr[size] = (temp)%10;
			temp /= 10;
			size++;
		}

		factorial(arr, size, n-1);				//given number is already stored in the array.

		for(short j=0; j<size; ++j)
			arr[j] = 0;
	}
	return 0;
}

void factorial(short arr[], short size, short num)
{
	short carry;

	while(num>1)
	{
		carry = 0;
		for(short i=0; i<size; ++i)					//loop for multiplication of each digit of number stored in array and computing carry.
		{
			arr[i] = ( (arr[i]) * num ) + carry;
			carry = (arr[i])/10 ;
			arr[i] = (arr[i])%10;
		}
		while(carry > 0)							//if carry remains in the end, increasing the size of stored number to store the actual number.
		{
			arr[size] = carry%10;
			carry /= 10;
			size++;
		}
		
		num--;
	}

	for(short i=(size-1); i>=0; --i)				//printing of the factorial.
		cout << arr[i];
	
	cout << endl;
}