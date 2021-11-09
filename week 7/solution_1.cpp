#include<iostream>
#include<vector>
using namespace std;

void dij(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<bool>visited(n,false);
    vector<int>dist(n,INT_MAX);
    int u;
    dist[0]=0;
    for(int i=0;i<n-1;i++)
    {
        u = -1;
        for(int j=0;j<n;j++)
        {
            if(visited[j]==false && (u==-1||dist[u]>dist[j]))
            {
                u = j;
            }
        }
        visited[u] = true;
        for(int i=0;i<n;i++)
        {
            if(grid[u][i]!=0 && visited[i]==false)
            {
                dist[i] = min(dist[i], dist[u]+grid[u][i]);
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