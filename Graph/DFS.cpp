class Solution {
  public:
    void dfs(int source, vector<int> adj[], vector<int> &vis, vector<int> &ans) {
        vis[source] = 1;
        ans.push_back(source);
        for (auto x : adj[source]) {
            if (!vis[x]) {
                dfs(x, adj, vis, ans);
            }
        }
        
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> ans;
        dfs(0, adj, vis, ans);
        return ans;
    }
};
