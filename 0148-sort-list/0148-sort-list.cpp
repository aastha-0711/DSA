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
private:
 // Returns the node *before* the middle so we can break the list
ListNode* findmiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return prev;
}


    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        return dummyNode->next;
    }

ListNode* mergesort(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* midPrev = findmiddle(head);
    ListNode* mid = midPrev->next;
    midPrev->next = nullptr;  // Break the list into two halves

    ListNode* left = mergesort(head);
    ListNode* right = mergesort(mid);
    return merge(left, right);
}

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        return mergesort(head);
    }
};
