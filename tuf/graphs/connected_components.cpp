#include<bits/stdc++.h>
using namespace std;
int countcomponents(vector<int>& n,vector<vector<int>>& e)
{
    vector<vector<int>>adj(n);
    for(auto &edges: e )
    {
        adj[edges[0]].push_back(edges[1]);
        adj[edges[1]].push_back(edges[0]);
    }
    vector<int>visited(n ,0);
    int components=0;
    for(int i=0;i<n;++i) {
        if (!visited[i]) {
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) 
            {
                int curr = q.front();
                q.pop();
                for (auto &nbr : adj[node]) 
                {
                    if (!visited[nbr]) 
                    {
                        visited[nbr] = 1;
                        q.push(nbr);
                    }
                }
            }
        }
    }
        return components;
}

int main()
{
    int n;
    cin>>n;
    vector<int>node(n);
    for(int i=0;i<n;i++)
    {
        cin>>node[i];
    }
    int m;
    cin>>m;
    vector<vector<int>>e(m,vector<int>(2));
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u >>v;
        e[i][0]=u;
        e[i][1]=v;
    }
    cout <<"Number of Connected Components: " <<countcomponents(node, e) << endl;
}