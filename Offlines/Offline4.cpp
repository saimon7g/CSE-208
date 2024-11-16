#include<bits/stdc++.h>
#define pb push_back
#define INF 1073741800
using namespace std;

int nCr(int n)
{
    int res= n*(n-1);
    return res/2;
}

bool bfs(int v,int** rGraph, int s, int t, int* parent)
{
    bool visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i]=false;
    }
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < v; i++)
        {
            if (visited[i] == false && rGraph[u][i] > 0)
            {
                q.push(i);
                parent[i] = u;
                visited[i] = true;
            }
        }
    }
    //cout<<visited[t]<<endl;
    return visited[t];
}

int fordFulkerson(int v,int** graph, int s, int t)
{
    int** rGraph;
    rGraph=new int*[v];
    for (int i=0; i<v; i++)
    {
        rGraph[i]=new int[v];
        for(int j=0; j<v; j++)
        {
            rGraph[i][j]=graph[i][j];
        }
    }
    int parent[v];
    int maxFlow = 0;

    // Updating the residual values of edges
    while (bfs(v,rGraph, s, t, parent))
    {
        //cout<<"here"<<endl;
        int path_flow = INT_MAX;
        int j;
        for (int i = t; i!=s; i = parent[i])
        {
            j = parent[i];
            path_flow = min(path_flow, rGraph[j][i]);
        }

        for (int i = t; i!=s; i = parent[i])
        {
            j = parent[i];
            rGraph[j][i] -= path_flow;
            rGraph[i][j] += path_flow;
        }

        // Adding the path flows
        maxFlow += path_flow;
    }

    return maxFlow;
}

class BaseballElimination
{
    struct Team
    {
        string Name;
        int win, loss, left;
        vector<int> game_left;
    };
    vector<Team> teams;

    bool eliminationCheck(int team_index)
    {
        int** graph;
        int** mat;
        vector<pair<int,int> > index;
        vector<int> match;
        int nodeNum=teams.size()+2+nCr(teams.size());
        mat=new int*[nodeNum];
        graph=new int*[nodeNum];
        for(int i=0; i<nodeNum; i++)
        {
            mat[i]=new int[nodeNum];
            graph[i]=new int[nodeNum];
            for(int j=0; j<nodeNum; j++)
            {
                graph[i][j]=0;
            }
        }
        cout<<"done"<<nodeNum<<"  "<<teams.size()<<" "<<team_index<<endl;

        for(int i=0; i<teams.size(); i++)
        {
            for(int j=0; j<teams.size(); j++)
            {
                if(i<j)
                {
                    index.pb(make_pair(i+1,j+1));
                    match.pb(teams[i].game_left[j]);
                }
            }
        }
        for(int i=0; i<match.size(); i++)
        {
            cout<<i<<" "<<index[i].first<<" "<<index[i].second<<" "<<match[i]<<endl;
        }
        cout<<"SFGHDFHDGH"<<endl;

        for(int i=0; i<match.size(); i++)
        {
            if(index[i].first!=(team_index+1 )&& index[i].second!=(team_index+1))
            {
                graph[0][i+1]=match[i];
                cout<<i<<"    "<<index[i].first<<" "<<index[i].second<<" "<<index[i].first+(nCr(teams.size()))<<" "<<index[i].second+(nCr(teams.size()))<<" b         qqqqqqqqqqqqqqq    "<<endl;
                graph[i+1][index[i].first+(nCr(teams.size()))]=match[i];
                graph[i+1][index[i].second+(nCr(teams.size()))]=match[i];
            }

        }
        int maxWin=teams[team_index].win+teams[team_index].left;
        for(int i=1; i<=teams.size(); i++)
        {
            graph[i+nCr(teams.size())][nodeNum-1]= maxWin-teams[i-1].win;
            if(i-1==team_index)
                graph[i+nCr(teams.size())][nodeNum-1]=0;

        }
        int maxflow=fordFulkerson(nodeNum,graph,0, nodeNum-1);
        cout<<maxflow<<"         tttttttttttttttttttttttttttt           "<<endl;

        int reaminingMatch=0;
        for(int i=0; i<teams.size(); i++)
        {
            for(int j=0; j<teams.size(); j++)
            {
                if(j>i && i!=team_index && j!=team_index)
                    reaminingMatch+=teams[i].game_left[j];
            }
        }
        return (reaminingMatch==maxflow);
    }


public:

    BaseballElimination()
    {
        int n;
        cin >> n;
        teams.resize(n);
        for (int i=0; i<n; i++)
        {
            cin >>teams[i].Name>> teams[i].win >> teams[i].loss >> teams[i].left;
            teams[i].game_left.resize(n);
            for (int j=0; j<n; j++)
                cin >> teams[i].game_left[j];
        }
        cout<<"input"<<endl;
    }

    void result()
    {
        for (int i=0; i<teams.size(); i++)
        {
            if(eliminationCheck(i))
            {
                cout<<teams[i].Name<<" not eliminated"<<endl;

            }
            else
                cout<<teams[i].Name<<" eliminated"<<endl;


        }
        cout<<"returned"<<endl;
    }
};

int main(int argc, char const *argv[])
{
    BaseballElimination baseball;
    baseball.result();
    return 0;
}
