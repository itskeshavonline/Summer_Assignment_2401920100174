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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // 1. Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 2. Reverse the second half in-place
        ListNode* prev = nullptr;
        ListNode* curr = slow; // Start reversing from the middle
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // 3. Compare both halves side-by-side
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // 'prev' is the head of the reversed half
        while (secondHalf) { // Only need to check until the end of the second half
            if (firstHalf->val != secondHalf->val) {
                return false; // Mismatch found, not a palindrome
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true;
    }
};