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
    long long totalSum = 0;
    long long mod = 1e9+7;

    void TotalSum(TreeNode* root)
    {
        if(root==NULL) return;
        TotalSum(root->left);
        TotalSum(root->right);
        totalSum += root->val;
    }

    long SubtreeSum(TreeNode* root,long long &maxPro)
    {
        if(root==NULL) return 0;

        long l = SubtreeSum(root->left,maxPro);
        long r = SubtreeSum(root->right,maxPro);

        long curr_sum = l + r + root->val;                                  
        long curr_Pro = (curr_sum * (totalSum - curr_sum));                 
        if(maxPro < curr_Pro)
            maxPro = curr_Pro;
        
        return curr_sum;                  
    }

    int maxProduct(TreeNode* root) 
    {
       
        TotalSum(root);
        long long maxPro = 1;
        SubtreeSum(root,maxPro);

        return (maxPro % mod);
    }
};