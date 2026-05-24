class Solution {
public:
    
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        
        if(dp[i] != -1)
            return dp[i];
        
        int n = arr.size();
        int ans = 1;
        
        // Move Right
        for(int j = i + 1; j <= min(i + d, n - 1); j++) {
            
            if(arr[j] >= arr[i])
                break;
            
            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }
        
        // Move Left
        for(int j = i - 1; j >= max(0, i - d); j--) {
            
            if(arr[j] >= arr[i])
                break;
            
            ans = max(ans, 1 + dfs(j, arr, d, dp));
        }
        
        return dp[i] = ans;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        
        vector<int> dp(n, -1);
        
        int res = 1;
        
        for(int i = 0; i < n; i++) {
            res = max(res, dfs(i, arr, d, dp));
        }
        
        return res;
    }
};