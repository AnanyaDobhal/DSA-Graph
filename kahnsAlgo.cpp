#include <bits/stdc++.h>
using namespace std;

class KahnsAlgo
{
public:
    void Bfs(vector<vector<int>> &adj, vector<int> &indeg, vector<int> &ans, queue<int> &q)
    {
        while (!q.empty())
        {
            int curnode = q.front();
            ans.push_back(curnode);
            q.pop();

            for (auto it : adj[curnode])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
    }

    vector<int> topoSort(int V, vector<vector<int>> &adj)
    {
        vector<int> indeg(V);
        for (int i = 0; i < V; i++)
        {
            for (auto neg : adj[i])
            {
                indeg[neg]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        Bfs(adj, indeg, ans, q);
        return ans;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    int u, v;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
        cout << "Enter edge " << i << " : ";
        cin >> u >> v;
        adj[u].push_back(v);
    }
    KahnsAlgo obj;

    vector<int> ans = obj.topoSort(V, adj);
    cout << "topological Sort: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}