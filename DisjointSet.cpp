#include <bits/stdc++.h>
using namespace std;
class Disjoint
{
    vector<int> rank, parent;

public:
    Disjoint(int n = 0)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionByRank(int u, int v)
    {
        int ult_p_u = findUParent(u);
        int ult_p_v = findUParent(v);

        if (ult_p_u == ult_p_v)
            return;
        if (rank[ult_p_u] < rank[ult_p_v])
            parent[ult_p_u] = ult_p_v;
        else if (rank[ult_p_u] > rank[ult_p_v])
            parent[ult_p_v] = ult_p_u;
        else
        {
            parent[ult_p_v] = ult_p_u;
            rank[ult_p_u]++;
        }
    }
};