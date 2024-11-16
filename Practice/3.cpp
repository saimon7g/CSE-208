#include<bits/stdc++.h>
#define pb push_back


using namespace std;

vector<int> flag;
vector<vector<int> > graph;
vector<vector<int> > weight;
bool res=true;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    flag[u] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto i = graph[v].begin(); i != graph[v].end(); i++)
        {
            if (flag[*i]==-1)
            {
                q.push(*i);
                flag[*i] = 1;
            }
        }
    }
}

void DFS(int v)
{

    flag[v] = 0;
//    cout << v << " ";
    for (auto i = graph[v].begin(); i != graph[v].end(); i++)
    {
        if (flag[*i]==-1)
            DFS(*i);

    }
    flag[v]=1;
}



int main()
{

    int Node,Edge;

    cin>>Node>>Edge;
    flag.assign(Node, -1);
    graph.assign(Node, vector<int>());
    weight.assign(Node, vector<int>());

    for(int i=0; i<Edge; i++)
    {
        int n1,n2,cost;
        cin>>n1>>n2;//>>cost;
        graph[n1].pb(n2);
        //graph[n2].pb(n1);
        //weight[n1].pb(cost);
        //weight[n2].pb(cost);
    }

    return 0;
}
