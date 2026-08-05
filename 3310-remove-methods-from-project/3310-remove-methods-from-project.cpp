class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = 1;
        for (int next : graph[node]) {
            if (!vis[next]) {
                dfs(next, graph, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);

        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        dfs(k, graph, vis);

        for (auto &e : invocations) {
            if (!vis[e[0]] && vis[e[1]]) {
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};