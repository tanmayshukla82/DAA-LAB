#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct myComp
{
    bool operator()(pair<int,int>p1, pair<int,int>p2)
    {
        return p1.first < p2.first;
    }
};
int main()
{
    vector<pair<int,int>>v;
    vector<int>selected;
    selected.push_back(1);
    cout << "Enter the value of n : ";
    int n;
    cin >> n;
    int start[n],ending[n];
    cout << "Enter the starting : ";
    for(int i=0;i<n;i++)
    {
        cin >> start[i];
    }
    cout << "Enter the ending time : ";
    for(int i=0;i<n;i++)
    {
        cin >> ending[i];
    }
    for(int i=0;i<n;i++)
    {
        v.push_back({ending[i],start[i]});
    }
    sort(v.begin(),v.end(),myComp());
    int res = 1;
    int prev = 0;
    for(int i=1;i<n;i++)
    {
        if(v[prev].first<=v[i].second)
        {
            res++;
            prev = i;
            selected.push_back(i+1);
        }

    }
    cout << "No. of non-conflicting activities : " << res;
    cout << "List of selected activities : ";
    for(int i=0;i<selected.size();i++)
    {
        cout << selected[i] << " ";
    }
}
