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
    int findBottomLeftValue(TreeNode* root) {
        
        queue<TreeNode*>q;
         q.push(root);
        int ans;
         while(!q.empty())
         {
              int n=q.size();
             ans=q.front()->val;
              for(int i=0;i<n;++i)
              {
                  TreeNode *last=q.front();
                  q.pop();
                  if(last->left)
                      q.push(last->left);
                  if(last->right)
                      q.push(last->right);
              }
         }
        return ans;
    }
};