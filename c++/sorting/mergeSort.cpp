#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int arr1[n1], arr2[n2]; 
    for(int i=0;i<n1;i++)
    {
        arr1[i] = arr[l + i];
    }
    //cout<<l<<" "<<m<<" "<<r<<endl;
    for(int j=0;j<n2;j++)
    {
        arr2[j] = arr[m+1+j];
    }
//cout<<l<<" "<<m<<" "<<r<<endl;
    i=0;j=0;k=l;
    
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
        
    }
    //cout<<l<<" "<<m<<" "<<r<<endl;
        

        while(i<n1)
        {
            
            arr[k] = arr1[i];
            k++;
            i++;
        }
        while(j<n2)
        {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    
    //printArray(arr,k);


}


void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 



int main()
{
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);
    
    printArray(arr,n);

}