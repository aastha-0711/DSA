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
    ListNode* reverse(ListNode* head)
    {
        ListNode*current=head;
        ListNode*prev=NULL;
        ListNode*next=NULL;
        while(current!=nullptr)
        {
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
            
        }head=prev;
        return head;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* temp =reverse(head);
        int count = 0;
        int sum = 0;
        while (temp != nullptr) {
            sum =sum+ temp->val * pow(2,count);
            count=count+1;
            temp = temp->next;
        }
        return sum;
    }
};