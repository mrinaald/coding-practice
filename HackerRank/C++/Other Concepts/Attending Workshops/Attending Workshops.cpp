#include <iostream>
#define MAX 100000

using namespace std;

struct Workshop
{
	int start_time;
	int duration;
	int end_time;
};

struct Available_Workshops
{
	int n;
	Workshop* w;
};

void merge(Workshop *w, int left, int mid, int right)
{
	int left_ulmt = mid;
	int j = mid+1;
	int i = left;
	int pos = left;
	Workshop ans[MAX];
	

	while( (i<=left_ulmt) && (j<=right))
	{
		if( w[i].end_time < w[j].end_time)
		{
			ans[pos] = w[i];
			pos++;
			i++;
		}
		else
		{
			ans[pos] = w[j];
			pos++;
			j++;
		}
	}
	
	if( i<=left_ulmt )
	{
		while( i<=left_ulmt )
		{
			ans[pos++] = w[i++];
		}
	}
	else if( j <= right )
	{
		while( j <= right )
		{
			ans[pos++] = w[j++];
		}
	}
	
	for( int k=left; k<pos; ++k)
		w[k] = ans[k];
}

void merge_sort(Workshop *w, int left, int right)
{
	if( left < right )
	{
		int mid = (left+right)/2;
		merge_sort(w, left, mid);
		merge_sort(w, mid+1, right);
		merge(w, left, mid, right);
	}
}

void merge_start(Workshop *w, int left, int mid, int right)
{
	int left_ulmt = mid;
	int j = mid+1;
	int i = left;
	int pos = left;
	Workshop ans[MAX];
	

	while( (i<=left_ulmt) && (j<=right))
	{
		if( w[i].start_time < w[j].start_time)
		{
			ans[pos] = w[i];
			pos++;
			i++;
		}
		else
		{
			ans[pos] = w[j];
			pos++;
			j++;
		}
	}
	
	if( i<=left_ulmt )
	{
		while( i<=left_ulmt )
		{
			ans[pos++] = w[i++];
		}
	}
	else if( j <= right )
	{
		while( j <= right )
		{
			ans[pos++] = w[j++];
		}
	}
	
	for( int k=left; k<pos; ++k)
		w[k] = ans[k];
}

void merge_sort_start(Workshop *w, int left, int right)
{
	if( left < right )
	{
		int mid = (left+right)/2;
		merge_sort_start(w, left, mid);
		merge_sort_start(w, mid+1, right);
		merge_start(w, left, mid, right);
	}
}

Available_Workshops* initialize (int start_time[], int duration[], int n)
{
	Available_Workshops* aw;
	aw = new Available_Workshops;
	aw->n = n;
	aw->w = new Workshop[n];

	for(int i=0; i<n; ++i)
	{
		aw->w[i].start_time = start_time[i];
		aw->w[i].duration = duration[i];
		aw->w[i].end_time = start_time[i]+duration[i];
	}

	return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
	int n = ptr->n;
	int i, j;
	int result=1;

	merge_sort(ptr->w, 0, n-1);		// sorting according to the end_time

	i=0;
	while(i<n)
	{
		j=i+1;
		while( (j<n) && (ptr->w[i].end_time == ptr->w[j].end_time) )
			j++;

		// sorting according to the start_time of workshops having the same end_time
		if( j < n )
			merge_sort_start(ptr->w, i, j-1);
		else
			merge_sort_start(ptr->w, i, n-1);

		i=j;
	}

	int end_time = ptr->w[0].end_time;

	int left=0;
	int right;
	while( left < n )
	{
		// finding the left and right limit of workshops having same end_time
		right=left+1;
		while( (right<n) && (ptr->w[left].end_time == ptr->w[right].end_time) )
			right++;
		
		for(j=left; j<right; ++j)
		{
			if( end_time <= ptr->w[j].start_time )
			{
				end_time = ptr->w[j].end_time;
                result++;
                break;
            }
		}

		left = right;
	}

	return result;
}

int main(int argc, char *argv[]) 
{
	std::ios::sync_with_stdio(false);
	int n; // number of workshops
	cin >> n;
	// create arrays of unknown size n
	int* start_time = new int[n];
	int* duration = new int[n];

	for(int i=0; i < n; i++)
	{
		cin >> start_time[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> duration[i];
	}

	Available_Workshops * ptr;
	ptr = initialize(start_time,duration, n);
	cout << CalculateMaxWorkshops(ptr) << endl;
	return 0;
}
