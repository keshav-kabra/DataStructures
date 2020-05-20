//program for quick sort
#include<bits/stdc++.h>
using namespace std;
int count_comparision =0;
int median(int start_index ,int mid ,  int end_index ,int a[])
{
    // int mid = (start_index + end_index)/2;
    // if(a[end_index] < a[start_index]) swap(a[end_index] , a[start_index]);
    // if (a[mid]<a[start_index]) swap(a[mid] , a[start_index]); 
    // if(a[end_index]<a[mid])  swap(a[end_index] , a[mid]);
    // return mid;

    if((a[start_index] > a[mid]) != (a[start_index]> a[end_index])) return start_index;
    else if((a[mid]>a[start_index]) != (a[mid]> a[end_index])) return mid;
    else return end_index;
    



}
int partitioning(int a[] , int start_index , int end_index)
{
    int pivot_index,i =0, j=start_index+1;
    //we select patitiom index as last element
    int mid = (start_index + end_index)/2;
    int pivot_choose = median(start_index ,mid, end_index, a);
    // cout<<"\nmedian element choosed is "<<pivot_choose;
    // swap(a[pivot_choose],a[end_index]);
    swap(a[pivot_choose], a[start_index]);
    pivot_index = start_index;
    for(i=start_index+1;i<=end_index;i++)
    {
        if(a[i] < a[pivot_index])
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[pivot_index], a[j-1]);
    pivot_index = j-1;

    return pivot_index;
}
void quick_sort(int a[], int start_index , int end_index)
{
    //base case
    if(start_index>=end_index) return;
    //do partitioning and select pivot index
    int pivot_index = partitioning(a , start_index, end_index);
    //sort the array of left
    int count = (end_index - start_index); 
    count_comparision += count;
    quick_sort(a , start_index , pivot_index-1);
    quick_sort(a , pivot_index+1 , end_index );
    

}
main()
{
    int a[10000];
    for(int i=0;i<10000;i++) cin>>a[i];
    quick_sort(a ,0, 9999);
    cout<<"sorted array is\n";
    for(int i=0;i<10000;i++) cout<<a[i]<<"\n";
    cout<<"number of comparisions : "<<count_comparision;


    
}