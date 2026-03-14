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

TreeNode* build(vector<int>& preorder, int preStart,
                vector<int>& inorder, int inStart, int inEnd) {

    if(preStart >= preorder.size() || inStart > inEnd)
        return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int index = inStart;

    while(inorder[index] != root->val)
        index++;

    int leftSize = index - inStart;

    root->left = build(preorder, preStart+1,
                       inorder, inStart, index-1);

    root->right = build(preorder, preStart+leftSize+1,
                        inorder, index+1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    return build(preorder, 0, inorder, 0, inorder.size()-1);
}
};