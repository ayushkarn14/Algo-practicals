#include <bits/stdc++.h>
#include "DisjointSet.cpp"
using namespace std;
vector<pair<int, pair<int, int>>> spanningTree(int n, vector<pair<int, pair<int, int>>> adj)
{
    Disjoint ds(n);
    sort(adj.begin(), adj.end());
    vector<pair<int, pair<int, int>>> result;
    for (auto it : adj)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUParent(u) != ds.findUParent(v))
        {
            result.push_back({w, {u, v}});
            ds.UnionByRank(u, v);
        }
    }
    return result;
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
    vector<pair<int, pair<int, int>>> adj; // adjacency list
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adj.push_back({w, {u, v}});
    }
    vector<pair<int, pair<int, int>>> ans = spanningTree(n, adj);
    int weight = 0;
    cout << "Edges in the min spanning tree: \n";
    for (auto it : ans)
    {
        weight += it.first;
        cout << it.second.first << " " << it.second.second << " " << it.first << endl;
    }
    cout << "Sum of weights : " << weight;
}