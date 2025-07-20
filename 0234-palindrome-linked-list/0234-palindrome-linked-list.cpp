class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }    
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move slow to middle
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half (start from slow)
        ListNode* secondHalfStart = reverseList(slow);
        ListNode* firstHalf = head;
        ListNode* secondHalf = secondHalfStart;

        bool isPalin = true;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Optional: restore list
        reverseList(secondHalfStart);

        return isPalin;
    }
};
