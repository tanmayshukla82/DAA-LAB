#include<iostream>
using namespace std;

int multiply(int p[], int n)
{
    int m[n][n];
    int i,j,k,l,q;
    for(i=0;i<n;i++)
    {
        m[i][i] = 0;
    }
    for(l=2;l<n;l++)
    {
        for(i = 1;i<n-l+1;i++)
        {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                if(q<m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

int main()
{
    cout << "Enter The value of n : ";
    int n;
    cin >> n;
    int arr[n][2];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
            cin >> arr[i][j];
    }
    int p[n+1];
    int index = 0;
    p[index] = arr[0][0];
    index++;
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            if(arr[i][j]!=p[index-1])
               {
                    p[index] = arr[i][j];
                    index++;
               }
        }
    }
    cout << multiply(p,n+1);
}
