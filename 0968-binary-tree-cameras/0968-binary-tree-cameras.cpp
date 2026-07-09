class Solution {
public:

    int camera = 0;

    // 0 - Not covered by the camera
    // 1 - has Camera
    // 2 - covered by the camera

    int dfs(TreeNode* root) {

        if (root == nullptr)
            return 2;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left == 0 || right == 0) {
            camera++;
            return 1;
        }

        if (left == 1 || right == 1)
            return 2;

        return 0;
    }

    int minCameraCover(TreeNode* root) {

        if (dfs(root) == 0)
            camera++;

        return camera;
    }
};