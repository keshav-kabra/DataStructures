//finding inversions in an array with time complexity (nlogn) using merge sort technique
#include<bits/stdc++.h>
using namespace std;
int merge(int a[] , int l[] , int r[],int size_l,int size_r)
{
    int i=0,j=0,k=0, count=0;
    while(i <size_l&& j <size_r)
    {
        if(l[i]<r[j]) a[k++] = l[i++];
        else
        {
            count += (size_l-i); 
            a[k++] = r[j++];
        }
    }
    while(i<size_l) a[k++] = l[i++];
    while(j <size_r) a[k++] = r[j++];

    return count;
}
int mergesort(int a[] , int size)
{
    if(size <2) return 0;
    //declare two array
    int *l = (int*)malloc((size/2)*sizeof(int));
    int *r = (int*)malloc(((size) -(size/2))*sizeof(int));
    // enter the array into l and r
    for(int i=0;i<size/2;i++) l[i] = a[i];
    for(int i= size/2;i<size; i++)  r[i-(size/2)] = a[i];
    mergesort(l , size/2);
    mergesort(r , (size)-(size/2));
    int count = merge(a , l , r , size/2 , size - (size/2));
    return count;
}
int inversion(int a[], int size)
{
    if(size<2) return 0;
    //divide array into two array
    int *l = (int*)malloc((size/2)*sizeof(int));
    int *r = (int*)malloc(((size) -(size/2))*sizeof(int));
    for(int i=0;i<size/2;i++) l[i] = a[i];
    for(int i= size/2;i<size; i++)  r[i-(size/2)] = a[i];
    int x = inversion(l , size/2);
    int y = inversion(r , size -(size/2));
    int z = mergesort(a , size);
    return x+y+z;

 
}
main()
{
    int a[6],size=0;
    for(int i=0;i<6;i++) cin>>a[i];
    int count = inversion(a , 6);
    cout<<"inversions are  "<<count;
    

}