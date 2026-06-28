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
        ListNode* prev = nullptr; // Initially, nothing is behind the head
        ListNode* curr = head;    
        
        while (curr != nullptr) {
            ListNode* nextNode = curr->next; // 1. Saving the next node (so we don't lose it)
            curr->next = prev;             // 2. Flip the arrow backward!
            
            // 3. Move both pointers one step forward for the next round
            prev = curr;                     
            curr = nextNode;                 
        } 
        
        // At the end, 'prev' will be at the new head of the reversed list
        return prev;
    }
};