#include<bits/stdc++.h>
#define pb push_back
#define INF 1073741800

using namespace std;

vector<vector< int > >graph;
vector<vector <int> >graphW;
pair <int, pair<int, int> > edge[1000];
int Adj[1000][1000];
int ret[1000][1000];

void print(int Node);
void floydwarshall(int N,int E)
{
    for(int i=1; i<N; i++)
    {
        for(int j=1; j<N; j++)
        {
            if(i!=j)
                Adj[i][j]=graphW[i][j];
            else
                Adj[i][j]=0;
        }
    }
    for(int k=1; k<N; k++)
    {
        for(int i=1; i<N; i++)
        {
            for(int j=1; j<N; j++)
            {
                Adj[i][j]=min(Adj[i][j],Adj[i][k]+Adj[k][j]);
            }
        }
    }
}
void EXTENDSHORTESTPATHS(int N)
{
    for(int i=1; i<N; i++)
    {
        for(int j=1; j<N; j++)
        {
            ret[i][j]=INF;
            for(int k=1; k<N; k++)
            {
                ret[i][j]=min(ret[i][j],Adj[i][k]+graphW[k][j]);
            }
        }
    }
}
void ALLPAIRSSHORTESTPATHS(int N)
{
    for(int i=1; i<N; i++)
    {
        for(int j=1; j<N; j++)
        {
            Adj[i][j]=graphW[i][j];
            if(i==j)
                Adj[i][j]=0;
        }
    }
    for(int m=2; m<N-1; m++)
    {
        EXTENDSHORTESTPATHS(N);
        for(int i=1; i<N; i++)
        {
            for(int j=1; j<N; j++)
                Adj[i][j]=min(ret[i][j],Adj[i][j]);
        }
    }
}

void print(int Node)
{
    for(int i=1; i<Node; i++)
    {
        for(int j=1; j<Node; j++)
        {
            if(Adj[i][j]==INF)
                cout<<"INF ";
            else
                cout<<Adj [i][j]<<"    ";
        }
        cout<<endl;
    }
}

int main()
{
    std::ifstream myfile ("apsp.txt");
    int Node,Edge;
    myfile>>Node>>Edge;
    Node++;
    graph.assign(Node, vector<int>());
    graphW.assign(Node, vector<int>());

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
        graph[x].pb(y);
        edge[i]=make_pair(z,make_pair(x,y));
    }
    floydwarshall(Node,Edge);
    //ALLPAIRSSHORTESTPATHS(Node);
    cout<<"Shortest distance matrix  "<<endl;
    print(Node);
    return 0;
}
