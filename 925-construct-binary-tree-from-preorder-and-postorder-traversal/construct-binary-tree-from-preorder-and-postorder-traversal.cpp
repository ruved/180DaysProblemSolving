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
       TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& postorder,
                     int preStart, int preEnd,
                     int postStart, int postEnd) {
        if (preStart > preEnd) return nullptr;
        
        TreeNode* node = new TreeNode(preorder[preStart]);
        
        if (preStart == preEnd) return node; // Leaf node
        
        // Find index of left child in postorder
        int leftChildInPostorder = find(postorder.begin() + postStart, postorder.begin() + postEnd + 1, preorder[preStart + 1]) - postorder.begin();
        int leftSubtreeSize = leftChildInPostorder - postStart + 1;
        
        node->left = helper(preorder, postorder,
                             preStart + 1,
                             preStart + leftSubtreeSize,
                             postStart,
                             leftChildInPostorder);
        
        node->right = helper(preorder, postorder,
                              preStart + leftSubtreeSize + 1,
                              preEnd,
                              leftChildInPostorder + 1,
                              postEnd - 1);
        
        return node;
    }
};