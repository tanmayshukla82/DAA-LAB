#include<iostream>
using namespace std;

void getDuplicate(char arr[], int n)
{
    int output[256] = {0};
    int res=INT_MIN;
    char index;
    for(int i=0;i<n;i++)
    {
        output[arr[i]]++;
    }
    for(int i=0;i<=255;i++)
    {
        if(output[i]>res)
        {
            res = output[i];
            index = i;
        }
    }
    if(res==1)
    {
        cout << "No Duplicates Present";
    }
    else{
        cout << index << " - " << res;
    }
}
int main()
{
    int t;
    cout << "Enter the number of test cases : ";
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cout << "enter the size of the array : ";
        cin >> n;
        char *arr = new char[n];
        cout << "Enter the elements in the array : ";
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        getDuplicate(arr,n);
        cout << endl;
    }
}