#include<iostream>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int j = low-1;
    for(int i=low;i<high;i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[j+1],arr[high]);
    return j+1;
}
int kthSmallest(int arr[], int low,int high, int k)
{
   int p = partition(arr,low,high);
   if(p==k-1)
   {
       return arr[p];
   }
   else if(p<k-1)
   {
       kthSmallest(arr,p+1,high,k);
   }
   else{
       kthSmallest(arr,low,p-1,k);
   }
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
    cout << "Enter the key : ";
    int key;
    cin >> key;
    int k = kthSmallest(arr,0,n-1,key);
    cout << "Kth smallest = " << k << endl;
}
}