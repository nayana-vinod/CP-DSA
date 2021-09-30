// QUESTION: https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        
        if(root->val > val) root->left = insertIntoBST(root->left, val); 
      /* implies the pointer is now back to root->left or new root->left = old root left or no change in root->left
        if return and save to root, then root = root->left => left subtree will be saved to root like in search */
        else if(root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};
