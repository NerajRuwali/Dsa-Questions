class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {

        queue<TreeNode*> q;
        vector<long long> levelSum;

        q.push(root);

        // First BFS: Store sum of every level
        while (!q.empty()) {

            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            levelSum.push_back(sum);
        }

        root->val = 0;

        q.push(root);

        int level = 0;

        // Second BFS: Replace values
        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                long long childrenSum = 0;

                if (node->left)
                    childrenSum += node->left->val;

                if (node->right)
                    childrenSum += node->right->val;

                if (node->left) {
                    node->left->val = levelSum[level + 1] - childrenSum;
                    q.push(node->left);
                }

                if (node->right) {
                    node->right->val = levelSum[level + 1] - childrenSum;
                    q.push(node->right);
                }
            }

            level++;
        }

        return root;
    }
};