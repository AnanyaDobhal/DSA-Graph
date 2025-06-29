#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void DFS(int node,vector<vector<int>>& adj,vector<int> &vis,stack<int> &st){
	vis[node] = 1;
	for(auto neg:adj[node])
	{
		if(!vis[neg]){
			DFS(neg,adj,vis,st);
		}
	}
	st.push(node);
}

int main() {
	int V,E;
	cin>>V>>E;
	int u,v;
	vector<vector<int>> adj(V+1);
	for(int i=1;i<=E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	vector<int> vis(V+1,0);
	stack<int> st;
	for(int i=1;i<=V;i++){
		if(!vis[i]){
			DFS(i,adj,vis,st);
		}
	}
	vector<int> ans;
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
}

//1-based indexing