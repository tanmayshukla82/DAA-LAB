#include<iostream>
using namespace std;
void common(int left[], int n, int right[], int m)
{
    int i=0,j=0;
     while(i<n && j<m)
    {
        if(left[i]==right[j])
        {
            cout << left[i] << " ";
            i++;
            j++;
        }
        else if(left[i]<right[j])
        {
            i++;
        }
        else{
            
            j++;
        }
    }
   
}
int main()
{
    int n;
    cout << "Enter the size of array 1 : ";
    cin >> n;
    int *arr1 = new int[n];
    cout << "Enter the element in the array 1: ";
    for(int i=0;i<n;i++)
    {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter the size of array 2 : ";
    cin >> m;
    int *arr2 = new int[m];
    cout << "Enter the element in the array 2 : ";
    for(int i=0;i<m;i++)
    {
        cin >> arr2[i];
    }

    common(arr1,n,arr2,m);
}