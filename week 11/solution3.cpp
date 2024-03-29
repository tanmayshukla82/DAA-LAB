#include<iostream>
using namespace std;

bool findPartition(int arr[], int n)
{
    int sum = 0;
    int i,j;

    for(int i=0; i<n; i++)
    {
        sum += arr[i];
    }

    if(sum%2!=0)
        return false;

    bool part[sum/2+1][n+1];

    for(int i=0;i<=n;i++)
    {
        part[0][i] = true;
    }

    for(int j=0;j<=sum/2;j++)
    {
        part[j][0] = false;
    }

    for(int i=1;i<=sum/2; i++)
    {
        for(int j=1;j<=n;j++)
        {
            part[i][j] = part[i][j-1];
            if(i>=arr[j-1])
            {
                part[i][j] = part[i][j] || part[i-arr[j-1]][j-1];
            }
        }
    }
    return part[sum/2][n];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    if(findPartition(arr,n)==true)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
