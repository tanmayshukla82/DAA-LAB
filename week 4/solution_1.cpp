#include<iostream>
using namespace std;
int merge(int arr[], int low, int mid, int high, int *comp)
{
    int n = mid-low+1, m = high-mid;
    int *left = new int[n];
    int *right = new int[m];
    int inv=0;
    for(int i=0;i<n;i++)
    {
        left[i] = arr[low+i];
    } 
    for(int j=0;j<m;j++)
    {
        right[j] = arr[mid+1+j];
    }
    int i=0,j=0,k=low;
    while(i<n && j<m)
    {
        if(left[i]<right[j])
        {
            arr[k++] = left[i++];
            (*comp) = (*comp)+1; 
        }
        else if(left[i]>right[j])
        {
            arr[k++] = right[j++];
            inv += (mid-i);
            (*comp) = (*comp)+1; 
        }

        while(i<n)
        {
            arr[k++] = left[i++];
        }
        while(j<m)
        {
            arr[k++] = right[j++];
        }
    }
    return inv; 
}
int mergeSort(int arr[], int low, int high, int *comp)
{
    int inv=0;
    if(low<high)
    {
        int mid = (low+high)/2;
        inv += mergeSort(arr,low,mid,comp);
        inv += mergeSort(arr,mid+1,high,comp);
        inv += merge(arr,low,mid,high,comp);
    }
    return inv;
}
int main()
{
    int t;
    cout << "Enter the number of test Cases : ";
    cin >> t;
    for(int i=1;i<=t;i++){
    cout << "Enter the number of elements in array : ";
    int n;
    cin >> n;
    cout << "Enter the elements in the array : ";
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int comp=0;
    int res = mergeSort(arr,0,n-1,&comp);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl <<"Inversions : " << res << endl <<"Comparisons : "<< comp << endl;
    }
    
}