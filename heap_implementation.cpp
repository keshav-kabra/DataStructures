#include<bits/stdc++.h>
using namespace std;
void bubbleup(int *a, int son );
void bubbledown(int *a, int end_index);
void read_heap();
void min_heapify(int *array, int start , int end);
int median_maintanence(int *a , int index);
int extract_min(int *a, int index);
void swap(int *a, int *b);

void print_arr(int *a , int index)
{
    cout<<"array :";
    for(int i=0;i<=index;i++) cout<<a[i]<<"\t";
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleup(int *a, int son )
{
    while(son!=0)
    {
        int dad = (son-1)/2;
        // cout<<"\nson is "<<a[son]<<"and dad is "<<a[dad]; 
        if(a[dad] > a[son]) 
        {  
            swap(&a[dad], &a[son]);
            // cout<<"  value is swaped";
        }
        else return;
        son = dad;
    }
}
void bubbledown(int array[], int end){
	int dad = 0, son = dad * 2 + 1;
	while(son <= end){
		if(son + 1 <= end && array[son + 1] < array[son])
			son = son + 1;
		if(array[dad] > array[son])
			swap(&array[dad], &array[son]);
		else
			return;
		dad = son;
		son = son * 2 + 1;
	}
	return;
}
// void bubbledown(int *a, int end_index)
// {
//     int dad = 0;
//     int son1 = (2*dad)+1;
//     int son2 = (2*dad)+2;
//     while(son1 <= end_index && son2 <= end_index)
//     {
//         if(a[dad] > a[son1])
//         {
//             swap(&a[dad], &a[son1]);
//             dad = son1;
//             son1 = (2*dad)+1;
//             son2 = (2*dad)+2;
            

//         }
//         else if(a[dad] > a[son2])
//         {
//             swap(&a[dad], &a[son2]);
//             dad = son2;
//             son1 = (2*dad)+1;
//             son2 = (2*dad)+2;
//         }
//         else 
//         return;

        
//     }
    

// }
void read_heap()
{
     int num=0 , a[10000] , index = -1 , sum =0;
    for(int i=0;i<20;i++) a[i] = 0;
    ifstream input;
    input.open("Median.txt");
    if(!input) cout<<"no file found";
    while(!input.eof())
    {
        input>>a[++index];
        bubbleup(a , index);
        sum += median_maintanence(a, index); //index is the last index position inthe arry till now


    }
    cout<<"total sum is "<<sum;
    

}
void min_heapify(int *array, int start , int end)
{
    int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		if (son + 1 <= end && array[son] > array[son + 1])
			son++;
		if (array[dad] < array[son])
			return;
		else {
			swap(&array[dad], &array[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}

}
int median_maintanence(int *a , int index)
{
    int length = index;
    int median =0;
    int median_index = index/2;
    for(int i=0;i<=median_index;i++)
    {
        median = extract_min(a, length);
        length--; 

    }
    for(int i=(index-1)/2;i>=0;i--) min_heapify(a , i , index);
    // cout<<"\nmedian is "<<median;    
    return median;
}
int extract_min(int *a, int index)
{
    int min = a[0];
    swap(&a[index], &a[0]);
    bubbledown(a , index-1);
    return min;
}
int main()
{
    read_heap();
    return 0;
}