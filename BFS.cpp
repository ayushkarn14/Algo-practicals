#include <bits/stdc++.h>
using namespace std;
vector<int> BFSTraversal(int n, vector<int> adj[])
{
    vector<int> bfs;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (int it : adj[node])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
        }
    }
    return bfs;
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
    vector<int> ans = BFSTraversal(v, adj);
    for (auto i : ans)
        cout << i << " ";
}