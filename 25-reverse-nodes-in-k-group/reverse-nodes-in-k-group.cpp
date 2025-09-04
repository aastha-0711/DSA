class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;  // return new head
    }

    // Finds the k-th node from head (0-indexed)
    ListNode* findKthNode(ListNode* head, int k) {
        while (head && --k > 0) {
            head = head->next;
        }
        return head;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;

        while (true) {
            ListNode* kth = findKthNode(prevGroupEnd->next, k);
            if (!kth) break;

ListNode* groupStart=prevGroupEnd->next;
ListNode* nextGroupStart=kth->next;
kth->next=nullptr;
ListNode* reverseHead=reverse(groupStart);
prevGroupEnd->next=reverseHead;
groupStart->next = nextGroupStart;
prevGroupEnd=groupStart;

        }

        return dummy->next;
    }
};
