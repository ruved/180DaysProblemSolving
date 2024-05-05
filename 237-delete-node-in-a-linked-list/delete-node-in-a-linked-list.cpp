/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *cur=node;
        
        while(cur&&cur->next&&cur->next->next)
        {
            ListNode *nxt=cur->next;
            cur->val=nxt->val;
            cur=nxt; 
        }
        cur->val=cur->next->val;
        cur->next=NULL;
       
    }
};