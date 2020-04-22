
    while(i <size_l&& j <size_r)
    {
        if(l[i]<r[j]) a[k++] = l[i++];
        else a[k++] = r[j++];
    }
    while(i<size_l) a[k++] = l[i++];