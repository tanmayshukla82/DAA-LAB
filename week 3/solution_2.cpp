#include<iostream>
using namespace std;
int main() {
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
        int comparisions = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                }
                comparisions++;
            }
        }
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl << "comparisions = " << comparisions << endl << "swaps = " << n-1;
        cout << endl;
    }
    return 0;
}