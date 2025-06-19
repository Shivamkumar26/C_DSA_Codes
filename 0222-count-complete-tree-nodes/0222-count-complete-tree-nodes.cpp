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
    int heightl(TreeNode* root) {
        if(!root) return 0;

        int h = 1;
        while(root->left) {
            root = root->left;
            h++;
        }
        return h;
    }
    int heightr(TreeNode* root) {
        if(!root) return 0;

        int h = 1;
        while(root->right) {
            root = root->right;
            h++;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int l = heightl(root->left);
        int r = heightr(root->right);

        if(l == r) return pow(2, l+1)-1;
        else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
/*

1  2^1-1
3 2^2-1
7 2^3-1
15

*/