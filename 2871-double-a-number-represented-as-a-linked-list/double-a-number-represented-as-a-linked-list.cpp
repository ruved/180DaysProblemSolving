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
ListNode* help(ListNode* head,int &carry){
    if(!head) return head;

    ListNode* nxt=help(head->next,carry);
    head->val=2*head->val+carry;
    carry=(head->val)/10;
    head->val=head->val%10;
    return head;
}
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        head=help(head,carry);
        if(carry==0)
        return head;

        ListNode *newNode=new ListNode(carry);
        newNode->next=head;
        return newNode;
    
    }
};