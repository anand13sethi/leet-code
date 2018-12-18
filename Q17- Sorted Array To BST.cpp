/*
Link - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree
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

TreeNode* makeTree(int p, int q, vector<int>& nums){
    if(q < p)
        return NULL;
    int mid = (p+q) >> 1;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = makeTree(p, mid-1, nums);
    node->right = makeTree(mid+1, q, nums);
    return node;
}


TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0)
        return NULL;
    return makeTree(0, nums.size()-1, nums);
}