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
        currRoot--;
        root->right = solve(preorder, mp, mp[root->val]+1, e);
        root->left = solve(preorder, mp, s, mp[root->val]-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();

        for(int i=0; i<n; i++) mp[inorder[i]] = i;
        currRoot = n-1;
        return solve(postorder, mp, 0, n-1);
    }
};