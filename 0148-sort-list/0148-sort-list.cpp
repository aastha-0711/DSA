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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* current=head;
        while(current!=nullptr){
            ans.push_back(current->val);
            current=current->next;
        }
        sort(ans.begin(),ans.end());
        current=head;
        for(int i=0;i<ans.size();i++){
current->val=ans[i];
current=current->next;
        }
        return head;

    }
};