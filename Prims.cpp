#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int>>> primsSpanTree(int n, map<int, vector<pair<int, int>>> adj)
{
    vector<int> parent(n + 1, -1);
    vector<bool> mst(n + 1, false);
    vector<int> key(n + 1, INT_MAX);

    key[1] = 0;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int j = 1; j <= n; j++)
        {
            if (!mst[j] && key[j] < mini)
            {
                mini = key[j];
                u = j;
            }
        }
        mst[u] = true;

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (!mst[v] && key[v] > w)
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    vector<pair<int, pair<int, int>>> res;
    for (int i = 2; i <= n; i++)
    {
        res.push_back({key[i], {i, parent[i]}});
    }
    return res;
}
int main()
{
    cout << "E: ";
    int e;
    cin >> e;
    cout << "V: ";
    int n;
    cin >> n;
    int u, v, w;
    map<int, vector<pair<int, int>>> adj; // adjacency list
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<pair<int, pair<int, int>>> ans = primsSpanTree(n, adj);
    int weight = 0;
    cout << "Edges in the min spanning tree: \n";
    for (auto it : ans)
    {
        weight += it.first;
        cout << it.second.first << " " << it.second.second << " " << it.first << endl;
    }
    cout << "Sum of weights : " << weight;
}