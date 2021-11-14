
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct myComp
{
    bool operator()(pair<int,int>p1, pair<int,int>p2)
    {
        return p1.second < p2.second;
    }
};
int main()
{
    vector<pair<int,int>>v;
    cout << "Enter the value of n : ";
    int n;
    cin >> n;
    vector<int>fillArray;
    int time[n],deadline[n];
    cout << "Enter the time : ";
    for(int i=0;i<n;i++)
    {
        cin >> time[i];
    }
    cout << "Enter the deadline : ";
    for(int i=0;i<n;i++)
    {
        cin >> deadline[i];
    }
    for(int i=0;i<n;i++)
    {
        v.push_back({time[i],deadline[i]});
    }
    sort(v.begin(),v.end(),myComp());
    int res = 0;
    int currentTime = 0;
    for(int i=0;i<n;i++)
    {
        if((v[i].second-currentTime)>=v[i].first)
        {
            res++;
            currentTime += v[i].first;
        }

    }

    cout << "Max number of tasks : " << res;
    /*cout << "selected task number : ";
    for(int i=0;i<selected.size();i++)
    {
        cout << selected[i] << " ";
    }*/
}
