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