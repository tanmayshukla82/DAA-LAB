#include <bits/stdc++.h>
using namespace std;
#define V 7

int primMST(int graph[V][V])
{

	int key[V];int res=0;
	fill(key,key+V,INT_MAX);
	bool mSet[V]; key[0]=0;

	for (int c = 0; c < V ; c++)
	{
		int u = -1;

		for(int i=0;i<V;i++)
		    if(!mSet[i]&&(u==-1||key[i]<key[u]))
		        u=i;
		mSet[u] = true;
		res+=key[u];


		for (int v = 0; v < V; v++)

			if (graph[u][v]!=0 && !mSet[v])
				key[v] = min(key[v],graph[u][v]);
	}
    return res;
}

int main()
{
	int graph[V][V] = { {0, 0, 7, 5, 0, 0, 0, },
						{0,0,8,5,0,0,0 },
						{7,8,0,9,7,0,0},
						{5,0,9,0,15,6,0},
	                    {0,5,7,15,0,8,9},
	                    {0,0,0,6,8,0,11},
	                    {0,0,0,0,9,11,0}
	};

	cout<<primMST(graph);

	return 0;
}
