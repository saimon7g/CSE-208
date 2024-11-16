#include<bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int> flag;
vector<vector<int> > graph;
vector<vector<int> > weight;
vector<int> indegree;

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    flag[u] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i<graph[v].size(); i++)
        {
            if (flag[graph[v][i]]==-1)
            {
                q.push(i);
                flag[graph[v][i]] =(flag[v]+1)%2;
            }
        }
    }
}

void DFS(int u)
{
    flag[u] = 0;
//    cout << u << " ";
    for (int i = 0; i<graph[u].size(); i++)
    {
        if (flag[i]==-1)
            DFS(i);
    }
    flag[u]=1;
}

void TopSort(int Node)
{
    queue<int> q;
    vector<int> solution;

    for(int i=0; i <Node; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        solution.pb(u);

        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }
}

int main()
{

    int Node,Edge;
    cin>>Node>>Edge;
    flag.assign(Node, -1);
    indegree.assign(Node, -1);
    graph.assign(Node, vector<int>());
    weight.assign(Node, vector<int>());

    for(int i=0; i<Edge; i++)
    {
        int n1,n2,cost;
        cin>>n1>>n2;//>>cost;
        graph[n1].pb(n2);
        graph[n2].pb(n1);
        //weight[n1].pb(cost);
        //weight[n2].pb(cost);
    }
    for (int i = 0; i < Node; i++)
    {
         if (flag[i]==-1)
            bfs(i);

    }
     bool res=true;
    for(int i=0;i<Node;i++){
        for(int j=0;j<graph[i].size();j++){
            if(flag[i]==flag[graph[i][j]])
                res= false;
        }
    }
    if (res==true)
        cout<<"BICOLORABLE."<<endl;
    else
     cout<<"NOT BICOLORABLE."<<endl;



    return 0;
}
