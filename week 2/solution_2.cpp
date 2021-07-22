#include<iostream>
using namespace std;

int bSearch(int arr[], int n, int k)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(arr[mid]==k)
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
        int flag = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum = arr[i]+arr[j];
                if(bSearch(arr,n,sum)!=-1)
                {
                    flag=1;
                    cout << i << " " << j << " " << bSearch(arr,n,sum) << endl;
                    break;
                }
            }
        }
        if(flag==0)
        {
            cout << "No sequence found" << endl;
        }
    }
}