void quick_sort(int arr[], int left, int right)		// right=n-1
{
	if(left > right)
		return;
	int pivot = left;
	int lim_left = left, lim_right = right;
	while(left < right)
	{
		while( (arr[left] <= arr[pivot]) && (left <= lim_right) )
			left++;
		while( (arr[right] > arr[pivot]) && (right >=lim_left ) )
			right--;
		if(left < right)
			swap(arr[left], arr[right]);
	}
	swap(arr[pivot], arr[right]);
	quick_sort(arr, lim_left, right-1);
	quick_sort(arr, right+1, lim_right);
}

void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
	return;
}