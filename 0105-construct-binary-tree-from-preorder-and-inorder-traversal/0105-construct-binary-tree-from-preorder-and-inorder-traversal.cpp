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
    int currRoot;
    TreeNode* solve(vector<int>& preorder, unordered_map<int, int>& mp, int s, int e) {
        int n = preorder.size();
        if(s > e) return NULL;

        TreeNode* root = new TreeNode(preorder[currRoot]);
        currRoot++;
        root->left = solve(preorder, mp, s, mp[root->val]-1);
        root->right = solve(preorder, mp, mp[root->val]+1, e);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) mp[inorder[i]] = i;

        currRoot = 0;
        return solve(preorder, mp, 0, n-1);
    }
};