#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int count=0;

void n_queens(int col[], int rows, int colms, int size, int q, int lim);

int main()
{

	int n, i, l;
	int col[20];	
	scanf("%d", &n);
	scanf("%d", &l);

	for(i=0; i<20; ++i)
		col[i]=INT_MIN;

	n_queens( col, 0, n, n, 0, l);
	printf("%d", count);
	return 0;
}

void n_queens(int col[], int rows, int colms, int size, int q, int lim)
{
	int flag=1;
	if( rows!= size)
	{
		for(int i=0; i<colms; ++i)
		{
			flag = 1;
			if(col[i]!=INT_MIN) 
				flag = 0;
			else
			{
				for( int j=0; j<colms; ++j)
				{
					if( ((rows+i)==(col[j]+j)) || ((i-rows)==(j-col[j])) )
					{
						if((abs(rows-col[j])<=lim))
						{
							flag = 0;
							break;
						}
					}
				}
			}
			if(flag)
			{
				col[i]=rows;
				n_queens(col, rows+1, colms, size, q+1, lim);
				col[i]= INT_MIN;
			}
		}
	}
	else
	{
		if( q==size )
			++count;
		return;
	}
}
