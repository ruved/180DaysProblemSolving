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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* cur=head;
      int len=k;
      ListNode *prev=NULL;
      while(len&&cur){
        cur=cur->next;
        len--;
      } 
      ListNode *Knext=cur;

      if(len==0){
        len=k;
        cur=head;
        ListNode* last=cur;
        while(cur&&len){
            ListNode *nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
            len--;
        }
        last->next=reverseKGroup(Knext,k);
        return prev;
      }
      else
        return head;
    }
};