#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge
{
    public :
        int source;
        int destination;
        int weight;
};
struct compare{

    bool operator()(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
};

vector<Edge> makeInput(int n)
{
    int arr[7][7] = {{0,0,7,5,0,0,0},{0,0,8,5,0,0,0},{7,8,0,9,7,0,0},{5,0,9,0,15,6,0},{0,5,7,15,0,8,9},{0,0,0,6,8,0,11},{0,0,0,0,9,11,0}};
    vector<Edge>input;
    Edge e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                Edge e;
                e.source = i;
                e.destination = j;
                e.weight = arr[i][j];
                input.push_back(e);
            }
        }
    }
    return input;
}

int findParent(vector<int>p, int i)
{
    if(p[i]==i)
        return i;
    return findParent(p,p[i]);
}
int kruskals(vector<Edge>input, int V)
{
    sort(input.begin(), input.end(), compare());
    vector<int>p;
    for(int i=0;i<V;i++)
        p.push_back(i);
    int c = 0;
    int i = 0;
    int res = 0;
    while(c != V-1)
    {
        Edge currentEdge = input[i];

        int sourceParent = findParent(p,currentEdge.source);
        int destinationParent = findParent(p,currentEdge.destination);


        if(sourceParent != destinationParent)
        {
            res += currentEdge.weight;
            c++;
            p[sourceParent] = destinationParent;
        }
        i++;
    }
    return res;
}
int main()
{
    int Vr=7;
    vector<Edge>v = makeInput(Vr);
    cout << kruskals(v,Vr);
}
