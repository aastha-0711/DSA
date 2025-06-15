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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        // Count total nodes using temp (not head)
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Edge case: delete the head node
        if (n == count) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Find the (count - n - 1)th node (node just before the one to remove)
        temp = head;
        for (int i = 0; i < count - n - 1; i++) {
            temp = temp->next;
        }

        // Delete the node
        ListNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
};
