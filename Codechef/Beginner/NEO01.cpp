#include <iostream>
#include <vector>

using namespace std;

//long int happiness(int*  int n, int index, int sum, int elem);
//long int happiness(int arr[], int n, int index, int sum, int elem);
//long int happiness(vector<int> & int n, int index, int sum, int elem);
long int happiness(int n, int index, int sum, int elem);
int max(int a, int b);

int arr[100000];

int main()
{
	std::ios::sync_with_stdio(false);
	int test, n;

	cin >> test;
	while(test--)
	{
		cin >> n;
		int temp;
		//int arr[100000];
		//vector<int> arr;
		//int *arr = new int[n];

		for(int i=0; i<n; ++i)
		{
			//cin >> temp;
			//arr.push_back(temp);
			cin >> arr[i];
		}

		cout << happiness(n,0,0,0) << endl;
		//cout << happiness( n,0,0,0) << endl;
		//delete[] arr;
	}
	return 0;
}

//long int happiness(int*  int n, int index, int sum, int elem)
//long int happiness(int arr[], int n, int index, int sum, int elem)
//long int happiness(vector<int> & int n, int index, int sum, int elem)
long int happiness(int n, int index, int sum, int elem)
{
	//return arr[n-1];
	if(index>=n)
	{
		//for(int i=0; i<n; ++i)
		//cout << arr[i] << ' ';
		return sum*elem;
	}

	if(arr[index]<0)
		return max( happiness(n,index+1,sum+arr[index],elem+1), happiness(n,index+1,sum,elem)+arr[index] );
	else
		return happiness(n,index+1,sum+arr[index],elem+1);

}

int max(int a, int b)
{
	return (a>b)?a:b;
}
