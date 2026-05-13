#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int node, vector<vector<int>>& isConnected,vector<int>& visited)
{
    visited[node]=1;
    for(int i=0;i<isConnected.size();i++)
    {
        if(isConnected[node][i]==1&&!visited[i])
        dfs(i,isConnected,visited);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>visited(n,0);
        int proviences=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,isConnected,visited);
                proviences++;
            }
        }
        return proviences;
    }
};
int main() {
    Solution sol;
    // Example input: [[1,1,0],[1,1,0],[0,0,1]]
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Number of Provinces: " << sol.findCircleNum(isConnected) << endl;
    return 0;
}