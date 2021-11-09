#include<iostream>
#include<vector>
using namespace std;

void dij(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int>dist(n,INT_MAX);
    int u;
    dist[0]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]!=0)
            {
                if(dist[i]!=INT_MAX && dist[j]>(dist[i]+grid[j][i]))
                {
                    dist[j] = min(dist[j],dist[i]+grid[j][i]);
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << dist[i] << " ";
    }
}
int main()
{
    vector<vector<int>>grid = {{0,4,1,0,0},{0,0,0,0,4},{0,2,0,4,0},{0,0,0,0,4},{0,0,0,0,0}};
    dij(grid);
}