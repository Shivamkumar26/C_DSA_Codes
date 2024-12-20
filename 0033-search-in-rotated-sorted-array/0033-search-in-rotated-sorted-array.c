int search(int* arr, int ele, int x) {
    int low=0,high=ele-1;

	while(low<=high)
	{
		int mid=low+(high-low)/2;
		
		printf("low=%d mid=%d high=%d\n",low,mid,high);
		if(arr[mid]==x)
			return mid;
		
		if(arr[mid]>=arr[low])
		{
			if(arr[low]<=x && arr[mid]>x)
				high=mid-1;
			else
				low=mid+1;
		}
		else
		{
			if(arr[high]>=x && arr[mid]<x)
				low=mid+1;
			else
				high=mid-1;
		}
		
	}
	return -1;
}