#include <iostream>

using namespace std;

void initialize_arr(short arr[], short size);
unsigned long int maxSum( unsigned long int sum, short curr_pos, short curr_row);

short arr[6000];
short size, rows;

int main()
{
	std::ios::sync_with_stdio(false);
	short n;

	cin >> n;

	for(short i=0; i<n; ++i)
	{
		cin >> rows;

		size = ( (rows)*(rows+1) )/2;

		// initialize_arr(arr, size);

		for(short j=0; j<size; ++j)
			cin >> arr[j];

		cout << maxSum( (unsigned long int)arr[0], 0, 1) << endl;
	}
	return 0;
}

void initialize_arr(short arr[], short size)
{
	for(short i=0; i<size; ++i)
		arr[i] = -1;

	return;
}

unsigned long int maxSum( unsigned long int sum, short curr_pos, short curr_row)
{
	if(curr_row > rows)
		return sum;

	unsigned long int sum1 = maxSum(sum + arr[curr_pos + curr_row], curr_pos + curr_row, curr_row+1);
	unsigned long int sum2 = maxSum(sum + arr[curr_pos + curr_row+1], curr_pos + curr_row+1, curr_row+1);

	if(  sum1 > sum2) 
		// maxSum(arr, size, rows, sum + arr[curr_pos + curr_row+1], curr_pos + curr_row+1, curr_row+1) )
		// return maxSum( arr, size, rows, sum + arr[curr_pos + curr_row], curr_pos+curr_row, curr_row+1);
		return sum1;
	else
		// return maxSum( arr, size, rows, sum + arr[curr_pos + curr_row+1], curr_pos+curr_row+1, curr_row+1);
		return sum2;
}