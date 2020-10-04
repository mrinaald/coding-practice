void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
	return;
}

void quick_sort(int arr[], int left, int right)		// right=n-1
{
	if(left > right)
		return;

  int pivot = right;
  int i, j;
  i = j = left;

  while(j < right){
    if (arr[j] < arr[pivot]){
      swap(arr[i], arr[j]);
      i++;
    }
    j++;
  }

  swap(arr[pivot], arr[i]);
	quick_sort(arr, left, i-1);
	quick_sort(arr, i+1, right);
}
