/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    TreeNode* parentX = NULL;
    TreeNode* parentY = NULL;

    int levelX = 0;
    int levelY = 0;

    void findNodeInfo(TreeNode* root, TreeNode* parent, int level, int x, int y) {

        if (root == NULL)
            return;

        if (root->val == x) {
            parentX = parent;
            levelX = level;
        }

        if (root->val == y) {
            parentY = parent;
            levelY = level;
        }

        findNodeInfo(root->left, root, level + 1, x, y);
        findNodeInfo(root->right, root, level + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {

        findNodeInfo(root, NULL, 0, x, y);

        if (levelX == levelY && parentX != parentY)
            return true;

        return false;
    }
};