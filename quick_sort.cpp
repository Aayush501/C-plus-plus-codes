#include <iostream>
using namespace std;

void sortAlgo(int arr[], int p, int l, int r)
{
    if(l>r)
    {
        return;
    }
    int s1=r, s2=l, s3=r;
    while(l<=r)
    {
        if(arr[r]>=arr[p])
        {
            r--;
        }
        if(arr[l]<=arr[p])
        {
            l++;
        }
        if(s1==r and s2==l)
        {
            arr[r] = arr[r]^arr[l];
            arr[l] = arr[r]^arr[l];
            arr[r] = arr[r]^arr[l];
        }
        else
        {
            s1=r;
            s2=l;
        }
    }
    arr[r] = arr[r]^arr[p];
    arr[p] = arr[r]^arr[p];
    arr[r] = arr[r]^arr[p];
    
    sortAlgo(arr, p, p+1, r-1);
    sortAlgo(arr, l, l+1, s3);
}

void quickSort(int arr[], int n)
{
    int p=0, l=1, r=n-1;
    sortAlgo(arr, p, l, r);
}

int main()
{
    cout<<endl<<endl;
    int a[9] = {9,5,7,10,12,8,4,6,2};
    cout<<"array before sorting : ";
    for(int i=0; i<9; i++)
    {
        cout<<a[i]<<" ";
    } 
    cout<<endl<<endl;
    quickSort(a, 9);
    cout<<"array after sorting : ";
    for(int i=0; i<9; i++)
    {
        cout<<a[i]<<" ";
    } 
    cout<<endl<<endl;
    
    return 0;
}