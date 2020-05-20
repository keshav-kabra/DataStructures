//finding inversions in an array with time complexity (nlogn) using merge sort technique
//modify array size according to need here i have taken a 100000 inout numbers
#include<bits/stdc++.h>
using namespace std;
long long merge(long long a[] , long long l[] , long long r[],long long size_l,long long size_r)
{
    long long i=0,j=0,k=0, count=0;
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
long long mergesort(long long a[] , long long size)
{
    if(size <2) return 0;
    //declare two array
    long long *l = (long long*)malloc((size/2)*sizeof(long long));
    long long *r = (long long*)malloc(((size) -(size/2))*sizeof(long long));
    // enter the array into l and r
    for(long long i=0;i<size/2;i++) l[i] = a[i];
    for(long long i= size/2;i<size; i++)  r[i-(size/2)] = a[i];
    mergesort(l , size/2);
    mergesort(r , (size)-(size/2));
    long long count = merge(a , l , r , size/2 , size - (size/2));
    return count;
}
long long inversion(long long a[], long long size)
{
    if(size<2) return 0;
    //divide array into two array
    long long *l = (long long*)malloc((size/2)*sizeof(long long));
    long long *r = (long long*)malloc(((size) -(size/2))*sizeof(long long));
    for(long long i=0;i<size/2;i++) l[i] = a[i];
    for(long long i= size/2;i<size; i++)  r[i-(size/2)] = a[i];
    long long x = inversion(l , size/2);
    long long y = inversion(r , size -(size/2));
    long long z = mergesort(a , size);
    return x+y+z;

 
}
main()
{
    long long *a = (long long*)malloc(100000*sizeof(long long)),size=0;
    for(long long i=0;i<100000;i++) cin>>a[i];
    long long count = inversion(a , 100000);
    cout<<"inversions are  "<<count;
    cout<<"\n";
    

}