#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> flag;
vector<vector<int> > graph;
vector<vector<int> > weight;

void bfs(int u)
{

    queue<int> q;
    q.push(u);
    flag[u] = 1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (auto i = graph[f].begin(); i != graph[f].end(); i++)
        {
            if (flag[*i]==-1)
            {
                q.push(*i);
                flag[*i] = (flag[f]+1)%2;
            }
        }
    }
}



int main()
{
   while(true) {
        flag.clear();
        graph.clear();


    int Node,Edge;
    cin>>Node;
    if(Node==0)
        return 0;
    cin>>Edge;
    flag.assign(Node, -1);
    graph.assign(Node, vector<int>());
  //  weight.assign(Node, vector<int>());

    for(int i=0; i<Edge; i++)
    {
        int n1,n2,cost;
        cin>>n1>>n2;
        //>>cost;
        graph[n1].pb(n2);
        graph[n2].pb(n1);
        //weight[n1].pb(cost);
        //weight[n2].pb(cost);



    }
    for (int i = 0; i < Node; i++) {
        if (flag[i]==-1)
            bfs(i);
    }

   // for(int i=0;i<Node;i++)
    //    cout<<flag[i]<<" ";
   // cout<<endl;
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

}
}
