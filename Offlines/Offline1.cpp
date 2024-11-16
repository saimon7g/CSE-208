#include<bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int> flag;
vector<vector<float> > graph;
pair <float, pair<int, int> > edge[1000];
vector <pair<int, int> > sol1;
vector <pair<int, int> > sol2;

float MSTPrim( int s,int N)
{
    flag[s]=1;
    float cost=0;
    priority_queue< pair <float, pair<int, int> > > pq;
    for(int i=0; i<N; i++)
    {
        if( graph[s][i]!=-1)
        {
            pq.push(make_pair((-1)*graph[s][i],make_pair(s,i)));
        }
    }
    while(!pq.empty())
    {
        pair <float, pair<int, int> > e=pq.top();
        pq.pop();
        float weight=e.first;
        int x=e.second.first;
        int y=e.second.second;
        //cout<<weight<<" "<<x<<" "<<y<<endl;
        if(flag[y]==-1)
        {
            flag[y]=1;
            cost+=weight;
            sol1.pb(make_pair(x,y));
            for(int i=0; i<N; i++)
            {
                if( graph[y][i]!=-1)
                {
                    pq.push(make_pair((-1)*graph[y][i],make_pair(y,i)));
                }
            }
        }
        //cout<<pq.size()<<endl;
    }
    return cost*(-1);
}

void unionSet(int a,int b,int N)
{
    int x=flag[a];
    int y=flag[b];
    for(int i=0; i<N; i++)
    {
        if(flag[i]==y)
            flag[i]=x;
    }
}

float MSTKruskal( int N,int E)
{
    flag.clear();
    for(int i=0; i<E; i++)
        flag.pb(i);
    sort(edge,edge+E);
    //for(int i=0;i<E;i++)
    //cout<<edge[i].first<<"edge weight"<<endl;
    int x,y;
    float cost=0,weight;

    for(int i=0; i<E; i++)
    {
        weight=edge[i].first;
        x=edge[i].second.first;
        y=edge[i].second.second;
        if(flag[x]!=flag[y])
        {
            cost+=weight;
            sol2.pb(make_pair(x,y));
            unionSet(x,y,N);
        }
    }
    return cost;
}

int main()
{
    std::ifstream myfile ("mst.in.txt");
    int N,E;
    myfile>>N>>E;
    graph.assign(N, vector<float>());
    flag.assign(N,-1);

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            graph[i].pb(-1);
    }

    for(int i=0; i<E; i++)
    {
        int x,y;
        float z;
        myfile>>x>>y>>z;
        graph[x][y]=z;
        graph[y][x]=z;
        edge[i]=make_pair(z,make_pair(x,y));
    }
    /*
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                cout<<graph[i][j]<<" ";
            cout<<endl;
        }
    */
    float minCost= MSTPrim(0,N);
    float minCostKruskal=MSTKruskal(N,E);
    cout<<"Cost of the minimum spanning tree : "<<minCost<<endl;
    //cout<<"Cost of the minimum spanning tree : "<<minCostKruskal<<endl;
    cout<<"List of edges selected by Prim’s: { ";
    for(int i=0; i<sol1.size(); i++)
    {
        cout<<"("<<sol1[i].first<<","<<sol1[i].second<<") ";
    }
    cout<<"}"<<endl<<"List of edges selected by Kruskal’s: { ";
    for(int i=0; i<sol2.size(); i++)
    {
        cout<<"("<<sol2[i].first<<","<<sol2[i].second<<") ";
    }
    cout<<"}"<<endl;
    return 0;
}
