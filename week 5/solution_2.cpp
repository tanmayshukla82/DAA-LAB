#include<iostream>
using namespace std;

void merge(int arr[], int low ,int mid ,int high)
{
    int *left = new int[mid-low+1];
    int *right = new int[high-mid];
    for(int i=0;i<(mid-low+1);i++)
    {
        left[i] = arr[low+i];
    }
    for(int i=0;i<(high-mid);i++)
    {
        right[i] = arr[mid+i+1];
    }
    int i=0,j=0,k=low;
    while(i<(mid-low+1) && j<(high-mid))
    {
        if(left[i]<right[j])
        {
            arr[k++] = left[i];
            i++;
        }
        else{
            arr[k++] = right[j];
            j++;
        }
    }
     while(i<(mid-low+1))
     {
        arr[k++] = left[i];
        i++;
    }
    while(j<(high-mid))
    {
        arr[k++] = right[j];
        j++;
    }
    
}
void mergeSort(int arr[], int low, int high)
{
    if(high>low)
    {
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void pairs(int arr[], int low, int high , int k)
{
    bool flag = false;
    mergeSort(arr,low,high);
    for(int i=0;i<=high;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    while(low<high)
    {
        if((arr[low]+arr[high])==k)
        {
            cout << arr[low] << " " << arr[high] << endl;
            low++;
            high--;
            flag = true;
        }
        else if((arr[low]+arr[high])>k)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    if(flag == false)
    {
        cout << "No such pair exists";
    }
   
}
int main() {
    int t;
    cout << "Enter the number of test cases : ";
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cout << "enter the size of the array : ";
        cin >> n;
        int *arr = new int[n];
        cout << "Enter the elements in the array : ";
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        cout << "Enter the key : ";
        int k;
        cin >> k;
        pairs(arr,0,n-1,k);
        cout << endl;
    }
}