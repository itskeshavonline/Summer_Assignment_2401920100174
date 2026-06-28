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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to act as the temporary starting point
        ListNode dummy(0); 
        ListNode* tail = &dummy; // 'tail' will track the end of our new merged list
        
        // Loop while both lists still have nodes left to compare
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;  // Attach list1's node to our new list
                list1 = list1->next; // Move forward in list1
            } else {
                tail->next = list2;  // Attach list2's node to our new list
                list2 = list2->next; // Move forward in list2
            }
            tail = tail->next; // Move our new list's tail forward
        }
        
        // If one list runs out of nodes first, attach the rest of the other list
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        // The real sorted list starts right after our dummy node
        return dummy.next;
    }
};