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

    TreeNode* cut(TreeNode* root) {

        if(root->left == NULL) {
            return root->right;
        }

        if(root->right == NULL) {
            return root->left;
        }

        TreeNode* rightChild = root->right;

        TreeNode* lastRight = root->left; // last node of the rightmost part

        while(lastRight->right != NULL) {
            lastRight = lastRight->right;
        }

        lastRight->right = rightChild;

        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL) {
            return NULL;
        }

        if(root->val == key) {
            return cut(root);
        }

        TreeNode* dummy = root;

        while(root != NULL) {

            if(key < root->val) {

                if(root->left != NULL && root->left->val == key) {
                    root->left = cut(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {

                if(root->right != NULL && root->right->val == key) {
                    root->right = cut(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }

        return dummy;
    }
};