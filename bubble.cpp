#include<iostream>
using namespace std;

int  bubblesort(int a[])
{
	int count = 0;
	for(int i=0;i<=4;i++)
	{
		int swap = 0;
		for(int j=0;j<=3;j++)
		{
			if(a[j]>a[j+1])
			{
				swap = 1;
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;

			}
		}

		if(swap != 0)
		count++; 
	}
	return count;



}
int  main()
{
	
	int k,a[] = {3,6,2,1,9};
	cout<<"\nunsorted array \n\n";
	for(k=0;k<=4;k++) cout<<a[k]<<"\t";
	int count = bubblesort(a);
	cout<<"\n\nsorted array \n\n";
	for(k =0;k<=4;k++)
	cout<<a[k]<<"\t";

	cout<<count;
	return 0;
}