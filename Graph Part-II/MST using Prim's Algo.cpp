class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            int u = it.second;
            int wt = it.first;
            pq.pop();
            if (vis[u] == 1) continue;
            vis[u] = 1;
            sum += wt;
            for (auto x : adj[u]) {
                if (!vis[x[0]]) {
                    pq.push({x[1], x[0]});
                } 
            }
        }
        return sum;
    }
};
