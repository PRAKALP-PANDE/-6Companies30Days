// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
     vector<bool> vis;
    int f,c,d;
    void dfs(vector<int> adj[],int v){
        vis[v]=true;
        for(auto x:adj[v]){
            if(f&&x==c&&v==d)continue;
            if(f&&x==d&&v==c)continue;
            if(!vis[x])dfs(adj,x);
        }
    }
    int isBridge(int n, vector<int> adj[], int C, int D) {
        vis.assign(n+1,false);
        int cc1=0,cc2=0;
        f=0;
        for(int i=0;i<n;i++){
            if(!vis[i])cc1++,dfs(adj,i);
        }
        f=1,c=C,d=D;
        vis.assign(n+1,false);
        for(int i=0;i<n;i++){
            if(!vis[i])cc2++,dfs(adj,i);
        }
        return cc1!=cc2;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends