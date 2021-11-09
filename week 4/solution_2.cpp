#include<iostream>
using namespace std;
int swaps=0;
void swaping(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    swaps++;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int j = low-1;
    for(int i=low;i<high;i++)
    {
        if(arr[i]<pivot)
        {
            j++;
            swaping(arr[j],arr[i]);
        }
    }
    swaping(arr[j+1],arr[high]);
    return j+1;
}
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
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
    swaps=0;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl <<"Swaps : "<< swaps << endl;
    }
    
}