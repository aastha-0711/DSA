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
    // Custom comparator for min heap
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap based on value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        // Push the head of each list into the minHeap
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }

        // Dummy node to build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // While heap is not empty, pop the smallest element and push its next
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
        }

        return dummy->next;
    }
};
