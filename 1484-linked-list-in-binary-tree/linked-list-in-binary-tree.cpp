/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
bool help(ListNode* head, TreeNode* root,bool parent){
    if(!head) return true;
    if(!root) return false;
    bool ans=false;
    if(head->val==root->val){
        
        ans|=help(head->next,root->left,true)||help(head->next,root->right,true);
    }
    if(!parent)
    ans|=help(head,root->left,false)||help(head,root->right,false);
    return ans;
}
    bool isSubPath(ListNode* head, TreeNode* root) {
        return help(head,root,false);
    }
};