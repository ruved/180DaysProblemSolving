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
void help(TreeNode* root,int num,int &sum){
    if(!root) return ;
    if(!root->left&&!root->right) { 
        num=num*10+root->val;
        sum+=num;
        return ;
    }
    int m=root->val;
    if(root->left) 
        help(root->left,num*10+m,sum);
    if(root->right) 
        help(root->right,num*10+m,sum);

}
    int sumNumbers(TreeNode* root) {
        int sum=0;
        help(root,0,sum);
        return sum;
    }
};