class Solution {
public:
    int n;
    vector<int> suffix;
    vector<vector<int>> dp;

    int dfs(int i, int M) {
        if (i >= n) return 0;

        if (2 * M >= n - i)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int x = 1; x <= 2 * M; x++) {
            ans = max(ans,
                      suffix[i] - dfs(i + x, max(M, x)));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        suffix.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        dp.assign(n, vector<int>(n + 1, -1));

        return dfs(0, 1);
    }
};