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
    vector<string> ans;
    void backtrack(TreeNode* root, string path) {
        if(root == NULL) {
            return;
        }
        path += "->" + to_string(root->val);
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        if(left == NULL && right == NULL) {
            ans.push_back(path);
            return;
        }
        backtrack(left, path);
        backtrack(right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string path = to_string(root->val);
        backtrack(root->left, path);
        backtrack(root->right, path);
        if(ans.size() == 0) ans.push_back(path);
        return ans;
    }
};