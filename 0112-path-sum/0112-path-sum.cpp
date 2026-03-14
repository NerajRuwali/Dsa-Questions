class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root == NULL) return false;

        // leaf node check
        if(root->left == NULL && root->right == NULL)
            return targetSum == root->val;

        int remaining = targetSum - root->val;

        return hasPathSum(root->left, remaining) || 
               hasPathSum(root->right, remaining);
    }
};