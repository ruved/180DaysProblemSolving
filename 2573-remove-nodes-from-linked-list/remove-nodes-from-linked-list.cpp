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
class Solution {
public:
    ListNode* help(ListNode* head,int &mx)
    {
        if(!head->next) { mx=head->val;return head;}
        ListNode*next=help(head->next,mx);//8
        if(head->val>=mx)
        {mx=head->val;  head->next=next;return head;}
        else
        return next;
    }
    ListNode* removeNodes(ListNode* head) {
        int mx=-1;
       return  help(head,mx);
    }
};