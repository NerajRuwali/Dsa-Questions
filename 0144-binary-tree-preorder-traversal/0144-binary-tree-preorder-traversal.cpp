/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* root){
        if(root == NULL) return;

        result.push_back(root->val); // visit root
        preorder(root->left);        // left subtree
        preorder(root->right);       // right subtree
    }

    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};