class Solution {
public:

unordered_map<long long, int> prefix;
int ans = 0;
void dfs(TreeNode* root , long long currentSum , int targetSum){
    if(root == nullptr)
     return;

     currentSum += root->val;

     if(prefix.count(currentSum - targetSum))
     ans += prefix[currentSum - targetSum];
     prefix[currentSum]++;
     
     dfs(root->left , currentSum , targetSum);
     dfs(root->right , currentSum , targetSum);

     prefix[currentSum]--;
}
    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        dfs(root , 0 , targetSum);
        return ans;
        
    }
};