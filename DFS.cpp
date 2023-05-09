#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &storeDFS)
{
    storeDFS.push_back(node);
    visited[node] = true;
    for (int it : adj[node])
    {
        if (!visited[it])
            dfs(it, adj, visited, storeDFS);
    }
}
vector<int> DFSTraversal(int n, vector<int> adj[])
{
    vector<int> storeDFS;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i < n + 1; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, storeDFS);
    }
    return storeDFS;
}
int main()
{
    cout << "Enter number of vertices and edges : ";
    int v, e;
    cin >> v >> e;
    vector<int> adj[v + 1];
    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans = DFSTraversal(v, adj);
    for (auto i : ans)
        cout << i << " ";
}
