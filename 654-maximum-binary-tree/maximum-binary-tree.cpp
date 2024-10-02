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
TreeNode* help(vector<int>& nums,int low,int hi){
    if(low>hi) return NULL;
    int index=max_element(nums.begin()+low,nums.begin()+hi+1)-nums.begin();
    cout<<low<<" "<<index<<" "<<hi<<"+";
    TreeNode *root=new TreeNode(nums[index]);
    root->left=help(nums,low,index-1);
    root->right=help(nums,index+1,hi);
    return root;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return help(nums,0,nums.size()-1);
    }
};