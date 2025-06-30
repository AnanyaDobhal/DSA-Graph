#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int cnt = 0;
class BfsCycle
{
public:
    void Bfs(vector<vector<int>> &adj, vector<int> &indeg, queue<int> &q)
    {
        while (!q.empty())
        {
            int curnode = q.front();
            cnt++;
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

    BfsCycle obj;
    obj.Bfs(adj, indeg, q);
    
    if (cnt == V)
        cout << "Cycle not Detected";
    else
        cout << "Cycle  Detected";
}