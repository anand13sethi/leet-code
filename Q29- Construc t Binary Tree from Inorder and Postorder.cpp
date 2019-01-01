/*
Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
*/

TreeNode *tree(vector<int>& inorder, int si, int se, vector<int>& postorder, unordered_map<int, int> m){
    if(si > se || postorder.size() <= 0)
        return NULL;
    int x = postorder.size()-1;
    TreeNode *node = new TreeNode(postorder[x]);
    unordered_map<int, int> ::iterator it;
    it = m.find(postorder[x]);
    int pos = it->second;
    postorder.pop_back();
    node->right = tree(inorder, pos+1, se, postorder, m);
    node->left = tree(inorder, si, pos-1, postorder, m);
    
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map <int, int> m;
    for(int i = 0; i < inorder.size(); i++){
        m.insert(pair<int, int> (inorder[i], i));
    }
    return tree(inorder, 0, inorder.size()-1, postorder, m);
}