#include<iostream>
#include <vector>
using namespace std;

void SelectionSort(int n)
{
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++)
	{
	    int min=i;
		for(int j=i;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				int temp=arr[min];
				arr[min]=arr[j];
                arr[j]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i]<<" ";
	}
}

int main()
{
	int n;
	cin>>n;
	SelectionSort(n);
	return 0;

}