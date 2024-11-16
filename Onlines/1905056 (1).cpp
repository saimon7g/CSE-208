#include<bits/stdc++.h>
#define pb push_back
#define INF 1073741824

using namespace std;

vector<int> flag;
vector<vector< int > >graph;
vector<vector <int> >graphW;
pair <int, pair<int, int> > edge[1000];
int parent[1000];


int BellmanFord(int N,int E,int S, int D)
{
    int distance[N];

    for(int i=0; i<N; i++)
        distance[i] = INF;

    distance[S]=0;

    for(int i=0; i<N-1; i++)
    {
        for(int j=0; j<E; j++)
        {
            int u=edge[j].second.first;
            int v=edge[j].second.second;
            int weight=edge[j].first;

            if(distance[u]!=INF && distance[u]+weight < distance[v])
            {
                parent[v]=u;
                distance[v]=distance[u]+weight;
            }
        }
    }

    for(int i=0; i<E; i++)
    {
        int u=edge[i].second.first;
        int v=edge[i].second.second;
        int weight=edge[i].first;

        if(distance[u]+weight < distance[v])
        {
            cout<<"The graph contains a negative cycle";
            return INF*(-1);
        }
    }
    return distance[D];
}

int djkastra(int N,int E,int S, int D)
{
    int distance[N];
    for(int i=0; i<N; i++)
        distance[i] = INF;

    priority_queue<pair <int,int> >q;
    pair<int,int> x;
    q.push(make_pair(0,S));
    while(!q.empty())
    {
        x=q.top();
        q.pop();
        int dis=x.first*(-1);
        int u=x.second;
        distance[u]=dis;
        for(int i=0; i<graph[u].size(); i++)
        {
            int v=graph[u][i];
            if(dis+graphW[u][v]<distance[v])
            {
                parent[v]=u;
                distance[v]= dis+graphW[u][v];
                q.push(make_pair(distance[v]*(-1),v));
            }
        }
    }
    return distance[D];
}

int main()
{
    std::ifstream myfile ("sssp.txt");
    int Node,Edge;
    myfile>>Node>>Edge;
    graph.assign(Node, vector<int>());
    graphW.assign(Node, vector<int>());
    flag.assign(Node,0);

    for(int i=0; i<Node; i++)
    {
        for(int j=0; j<Node; j++)
            graphW[i].pb(INF);
    }

    for(int i=0; i<Edge; i++)
    {
        int x,y,z;
        myfile>>x>>y>>z;
        graphW[x][y]=z;
        //graphW[y][x]=z;
        graph[x].pb(y);
        //graph[y].pb(x);
        edge[i]=make_pair(z,make_pair(x,y));
    }
    /*

        for(int i=0; i<Node; i++)
        {
            for(int j=0; j<Node; j++)
                cout<<graphW[i][j]<<" ";
            cout<<endl;
        }
        for(int i=0; i<Node; i++)
        {
            for(int j=0; j<graph[i].size(); j++)
                cout<<graph [i][j]<<" ";
            cout<<endl;

        }

    */

    int Source,Dest;
    myfile>>Source>>Dest;
    int cost;


     cost=djkastra(Node,Edge,Source,Dest);
      cout<<"Shortest path cost:  "<<cost<<endl;



   // cost=BellmanFord(Node,Edge,Source,Dest);
   // if(cost==(-1)*INF)
    //    return 0;
    //cout<<"The graph does not contain a negative cycle"<<endl<<"Shortest path cost: "<<cost<<endl;



    int u=Dest;
    stack<int> sol;
    while(u!=Source)
    {
        sol.push(u);
        u=parent[u];
    }
    sol.push(Source);
    while(!sol.empty())
    {
        cout<<sol.top()<<"->";
        sol.pop();
    }
    return 0;
}

