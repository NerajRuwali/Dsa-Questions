class Solution {
public:
    static const int MOD = 1e9 + 7;

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int d = 0;
        vector<vector<int>> g(edges.size() + 2);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        queue<pair<int,int>> q;
        vector<int> vis(g.size(), 0);
        q.push({1, 0});
        vis[1] = 1;

        while (!q.empty()) {
            auto [u, dep] = q.front(); q.pop();
            d = max(d, dep);

            for (int v : g[u])
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, dep + 1});
                }
        }

        long long ans = 1, base = 2;
        int p = d - 1;

        while (p > 0) {
            if (p & 1) ans = ans * base % MOD;
            base = base * base % MOD;
            p >>= 1;
        }

        return ans;
    }
};