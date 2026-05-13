#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V), revAdj(V);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            revAdj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        int candidate = -1;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                candidate = i;
            }
        }

        fill(vis.begin(), vis.end(), 0);
        dfs(candidate, adj, vis);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) return -1;
        }

        fill(vis.begin(), vis.end(), 0);
        dfs(candidate, revAdj, vis);

        int ans = candidate;
        for (int i = 0; i < V; i++) {
            if (vis[i]) {
                ans = min(ans, i);
            }
        }

        return ans;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    cout << obj.findMotherVertex(V, edges);

    return 0;
}