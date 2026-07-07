
class Solution {
public:

    bool isMirror(TreeNode* left, TreeNode* right){

        if(left == NULL && right == NULL)
            return true;

        if(left == NULL || right == NULL)
            return false;

        if(left->val != right->val)
            return false;

        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};