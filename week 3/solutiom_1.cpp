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
        int shifts = 0;
        for(int i=1;i<n;i++)
        {
            int key = arr[i];
            int j = i-1;
            shifts++;
            while(j>=0 && key<arr[j])
            {
                arr[j+1] = arr[j];
                j--;
                comparisions++;
                shifts++;
            }
            arr[j+1]=key;

        }
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl << "comparisions = " << comparisions << endl << "shifts = " << shifts;
        cout << endl;
    }
    return 0;
}