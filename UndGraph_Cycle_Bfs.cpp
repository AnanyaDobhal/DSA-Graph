#include<bits/stdc++.h>
using namespace std;
class CycleBFS {
  public:
  
     bool detectcycle(int s,vector<vector<int>>& adj,int vis[]){
        vis[s] = 1;
        queue<pair<int,int>> q;
        q.push({s,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it,node});
                }
                else if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    
     bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        int vis[n] = {0};
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detectcycle(i,adj,vis) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int V,E;
	cin>>V>>E;
	int u,v;
	vector<vector<int>> adj(V);
	for(int i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
        adj[v].push_back(u);
	}
    CycleBFS cf ;
    if(cf.isCycle(adj)){
        cout<<"Cycle Detected";
    }
    else{
        cout<<"Cycle not Detected";
    }
}