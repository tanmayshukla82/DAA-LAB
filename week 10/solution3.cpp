#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in the array : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int c = 1;
    int res = 0;
    for(int i=1;i<n;i++)
    {
        if(arr[res]==arr[i])
        {
            c++;
        }
        else{
            c--;
        }
        if(c==0)
        {
            res = i;
            c = 1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[res]==arr[i])
        {
            c++;
        }
    }
    if(c>=n/2)
    {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    int median;
    sort(arr,arr+n);
    if(n%2==0)
    {
        median = (arr[n/2]+arr[(n/2)-1])/2;
    }
    else
    {
        median = arr[n/2];
    }
    cout << endl << median;
}
