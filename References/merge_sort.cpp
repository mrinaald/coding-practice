void merge(int arr[], int left, int mid, int right)
{
	int left_ulmt = mid;
	int j = mid+1;
	int i = left;
	int pos = left;
	int ans[MAX];
	

	while( (i<=left_ulmt) && (j<=right))
	{
		if( arr[i] < arr[j])
		{
			ans[pos] = arr[i];
			pos++;
			i++;
		}
		else
		{
			ans[pos] = arr[j];
			pos++;
			j++;
		}
	}
	
	if( i<=left_ulmt )
	{
		while( i<=left_ulmt )
		{
			ans[pos++] = arr[i++];
		}
	}
	else if( j <= right )
	{
		while( j <= right )
		{
			ans[pos++] = arr[j++];
		}
	}
	
	for( int k=left; k<pos; ++k)
		arr[k] = ans[k];
}

void merge_sort(int arr[], int left, int right)		// right=n-1
{
	if( left < right )
	{
		int mid = (left+right)/2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}