//program for quick sort
#include<bits/stdc++.h>
using namespace std;
int partitioning(int a[] , int start_index , int end_index)
{
    int pivot_index,i =0, j=start_index;
    //we select patitiom index as last element
    pivot_index = end_index;
    for(i=start_index;i<=end_index;i++)
    {
        if(a[i] < a[pivot_index])
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[pivot_index], a[j]);
    pivot_index = j;

    return pivot_index;
}
void quick_sort(int a[], int start_index , int end_index)
{
    //base case
    if(start_index>=end_index) return;
    //do partitioning and select pivot index
    int pivot_index = partitioning(a , start_index, end_index);
    //sort the array of left 
    quick_sort(a , start_index , pivot_index-1);
    cout<<"done here";
    quick_sort(a , pivot_index+1 , end_index );
    cout<<"done here 2";
    

}
main()
{
    int a[8];
    for(int i=0;i<8;i++) cin>>a[i];
    quick_sort(a ,0, 7);
    cout<<"sorted array is\n";
    for(int i=0;i<8;i++) cout<<a[i]<<"\t";


    
}