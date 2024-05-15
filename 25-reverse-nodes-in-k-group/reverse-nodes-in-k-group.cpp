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
ListNode *reverse(ListNode* head,int k){
    ListNode *prev=NULL,*cur=head,*nxt;
    while(k--)
    {
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* cur=head;
        int i=0;
        while(i<k&&cur){
            cur=cur->next;
            ++i;
        }
        if(i<k) return head;

        ListNode *nxt=cur;
        ListNode *rev=reverse(head,k);
        ListNode *second=reverseKGroup(nxt,k);
        head->next=second;
        return rev;
    }
};