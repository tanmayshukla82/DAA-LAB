#include<iostream>
using namespace std;

void merge(int arr[], int low,int mid ,int high)
{
    int *left = new int[mid-low+1];
    int *right = new int[high-mid];
    for(int i=0;i<(mid-low+1);i++)
    {
        left[i] = arr[low+i];
    }
    for(int j=0;j<(high-mid);j++)
    {
        right[j] = arr[mid+j+1];
    }
    int i=0,j=0,index=low;
    while(i<(mid-low+1) && j<(high-mid))
    {
        if(left[i]<=right[j])
        {
            arr[index] = left[i];
            i++;
        }
        else{
            arr[index] = right[j];
            j++;
        }
        index++;
    }
    while(i<mid-low+1)
    {
        arr[index] = left[i];
        i++;
        index++;

    }
    while(j<high-mid)
    {
        arr[index] = right[j];
        j++;
        index++;
    }
}
void mergeSort(int arr[], int low, int high)
{
    if(high<=low)
        return;

    int mid = low+(high-low)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
bool check(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int t;
    cout << "Enter the number of test cases : ";
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        cout << "Enter the size of array : ";
        int n;
        cin >> n;
        int arr[100];
        cout << "Enter the elements in the array : ";
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        mergeSort(arr,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        if(check(arr,n))
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}