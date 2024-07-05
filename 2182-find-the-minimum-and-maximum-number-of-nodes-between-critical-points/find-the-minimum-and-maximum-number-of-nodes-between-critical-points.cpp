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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *cur=head->next;
        ListNode *prev=head;
        vector<int>ans;
        int count=2;
        while(cur->next){
            int x=cur->val;
            int y=prev->val;
            int z=cur->next->val;
            if((x>y&&x>z)||(x<y&&x<z))
            ans.push_back(count);
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(ans.size()<2) return {-1,-1};
        sort(ans.begin(),ans.end());
        int maxdis=ans[ans.size()-1]-ans[0];
        int mindis=INT_MAX;
        for(int i=1;i<ans.size();++i)
        {
            mindis=min(mindis,ans[i]-ans[i-1]);
        }
        return {mindis,maxdis};
    }
};