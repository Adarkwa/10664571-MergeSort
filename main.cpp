 #include <iostream>

    using namespace std;

void Merge(int *a, int small, int big, int half)
{

	int i, j, k, temp[big-small+1];
	i = small;
	k = 0;
	j = half + 1;

	while (i <= half && j <= big)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= half)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= big)
	{
		temp[k] = a[j];
		k++;
		j++;
	}

	for (i = small; i <= big; i++)
	{
		a[i] = temp[i-small];
	}
}

void MergeSort(int *a, int small, int big)
{
	int half;
	if (small < big)
	{
		half=(small+big)/2;

		MergeSort(a, small, half);
		MergeSort(a, half+1, big);

		Merge(a, small, big, half);
	}
}
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}

	MergeSort(arr, 0, n-1);

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<"->"<<arr[i];

	return 0;
}
