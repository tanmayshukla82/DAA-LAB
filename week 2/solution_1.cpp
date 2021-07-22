#include<iostream>
using namespace std;
int firstOccurance(int arr[], int n, int k)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(arr[mid]==k && (arr[mid-1]!=k||mid==0))
        {
            return mid;
        }
        else if(arr[mid]>=k)
        {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int lastOccurance(int arr[], int n, int k)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(arr[mid]==k && (arr[mid+1]!=k||mid==n-1))
        {
            return mid;
        }
        else if(arr[mid]>k)
        {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}
int main()
{
    int t;
    cout << "Enter the number of test cases : ";
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        
        cout << "Enter the number of integers you want to enter : ";
        int n;
        cin >> n;
        int arr[100];
        cout << "Enter elemnts in array : ";
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        cout << "Enter the key to be searched : ";
        int k;
        cin >> k;
        int a = firstOccurance(arr,n,k);
        int b = lastOccurance(arr,n,k);
        if(a==-1||b==-1)
            cout << "Not Present";
        else{
            cout << (b-a)+1 << endl; 
        }
    }
}