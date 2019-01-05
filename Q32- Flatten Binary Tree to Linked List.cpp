/*
Link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void toList(TreeNode *node, TreeNode* &prev){
    if(!node)
        return;
    toList(node->right, prev);
    toList(node->left, prev);
    node->left = NULL;
    node->right = prev;
    prev = node;
}

void flatten(TreeNode* root) {
    TreeNode * prev = nullptr;
    toList(root, prev);
}