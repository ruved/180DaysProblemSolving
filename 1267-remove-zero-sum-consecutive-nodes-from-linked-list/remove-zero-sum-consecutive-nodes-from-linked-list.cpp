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
    
//     bool checkBackward(int dt,stack<ListNode*>&st)
//     {
//         stack<ListNode*>temp;
//         while(dt<0&&!st.empty())
//         {
//             temp.push(st.top());
//             dt+=st.top()->val;
//             st.pop();
//         }
//         if(dt!=0)
//         {
//             while(!temp.empty())
//             {
//                 st.push(temp.top());
//                 temp.pop();
//             }
//             return false;
//         }
//         else
//         {
//             while(!temp.empty())
//             {
//                 ListNode *cur=temp.top();
//                 temp.pop();
//                 delete cur;
//             }
//             return true;
//         }
            
//     }
    
    
    ListNode* removeZeroSumSublists(ListNode* head) {
   
       ListNode* dummy = new ListNode(0), *cur = dummy;
        dummy->next = head;
        int prefix = 0;
        map<int, ListNode*> m;
        while (cur) {
            prefix += cur->val;
            if (m.count(prefix)) {
                cur =  m[prefix]->next;
                int p = prefix + cur->val;
                while (p != prefix) {
                    m.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                m[prefix]->next = cur->next;
            } else {
                m[prefix] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};