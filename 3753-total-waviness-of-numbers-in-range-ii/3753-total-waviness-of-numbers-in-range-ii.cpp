class Solution {
    struct Node {
        long long cnt, wav;
    };

    string s;
    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int i, int p2, int p1, int st, int tight) {
        if (i == s.size()) return {1, 0};

        if (vis[i][p2][p1][st][tight])
            return dp[i][p2][p1][st][tight];

        vis[i][p2][p1][st][tight] = 1;
        Node res = {0, 0};

        int lim = tight ? s[i] - '0' : 9;

        for (int d = 0; d <= lim; d++) {
            int nt = tight && (d == lim);

            if (!st && d == 0) {
                auto t = dfs(i + 1, 10, 10, 0, nt);
                res.cnt += t.cnt;
                res.wav += t.wav;
            } else {
                int add = (st && p2 != 10 &&
                          ((p1 > p2 && p1 > d) ||
                           (p1 < p2 && p1 < d)));

                auto t = dfs(i + 1, st ? p1 : 10, d, 1, nt);

                res.cnt += t.cnt;
                res.wav += t.wav + add * t.cnt;
            }
        }

        return dp[i][p2][p1][st][tight] = res;
    }

    long long calc(long long x) {
        if (x <= 0) return 0;
        s = to_string(x);
        memset(vis, 0, sizeof(vis));
        return dfs(0, 10, 10, 0, 1).wav;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};