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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
       
       ListNode *cur=list1;
       ListNode *remove,*tail;
        int len=1;
        if(a>0){
            while(len<a)
            {
                cur=cur->next;
                len++;
            }
            remove=cur->next;
            cur->next=list2;
        }
     
        while(len<=b)
        {
                remove=remove->next;
                len++;
        }
        ListNode *cur2=list2;
        while(cur2->next)
            cur2=cur2->next;
            cur2->next=remove;
        return a==0?list2:list1;
    }
};