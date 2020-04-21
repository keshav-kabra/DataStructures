//we do from starting

#include<bits/stdc++.h>
using namespace std;
int merge(int a[] , int l[] , int r[],int size_l,int size_r)
{
    int i=0,j=0,k=0;
    while(i <size_l&& j <size_r)
    {
        if(l[i]<r[j]) a[k++] = l[i++];
        else a[k++] = r[j++];
    }
    while(i<size_l) a[k++] = l[i++];
    while(j <size_r) a[k++] = r[j++];


    return 0;
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
    
    //try print in both arrays
    // for(int i=0;i<size/2;i++) cout<<l[i]<<"\t";
    // cout<<"\n";
    // for(int i=0;i<(size/2);i++) cout<<r[i]<<"\t";

    mergesort(l , size/2);

    mergesort(r , (size)-(size/2));
    merge(a , l , r , size/2 , size - (size/2));
    return 0;
}
main()
{
    int a[6],size=0;
    for(int i=0;i<6;i++) cin>>a[i];
    int count = mergesort(a , 6);
    // cout<<"inversions are"<<count;
    cout<<"\n";
    for(int i=0;i<6;i++) cout<<a[i]<<"\t";


}