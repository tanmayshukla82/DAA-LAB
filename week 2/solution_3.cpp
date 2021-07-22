#include<iostream>
#include<unordered_set>
using namespace std;

bool bSearch(int arr[], int n, int k)
{
    int low = 0;
    int high = n-1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(arr[mid]==k)
        {
            return true;
        }
        else if(arr[mid]>k)
        {
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return false;
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
        int count = 0;
        // for(int i=0;i<n;i++)
        // {
        //     int diff = arr[i]-k;
        //     if(bSearch(arr,n,diff))
        //     {
        //         count++;
        //     }
        // }
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            if(s.find(arr[i]+k)!=s.end())
            {
                count++;
            }
            else{
                s.insert(arr[i]);
            }
        }
        cout << count*2 << endl;
    }
}