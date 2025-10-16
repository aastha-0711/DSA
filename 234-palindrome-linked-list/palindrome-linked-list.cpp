class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr=head;
           if(head==nullptr || head->next==nullptr){
            return head;
        }
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
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

        reverseList(secondHalfStart);

        return isPalin;
    }
};
