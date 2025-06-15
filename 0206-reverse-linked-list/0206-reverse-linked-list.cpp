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
    ListNode* reverseList(ListNode* head) {
        ListNode*curr=head;
        ListNode*temp=nullptr;
        if(head==nullptr || head->next==nullptr){
            return head;
        }
      while (curr != nullptr) {
            ListNode* nodee = curr->next;  // store next
            curr->next = temp;             // reverse pointer
            temp = curr;                   // move temp to current
            curr = nodee;                  // move curr to original next
        }
         return temp;
    }
};