/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Iterative two-pointers approach
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
        if (!head) return nullptr;
        ListNode* tail = nullptr;
        ListNode* lead = head;
        while (lead) {
            ListNode* temp = lead->next;
            lead->next = tail;
            tail = lead;
            lead = temp;
        }
        return tail;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Recursive approach
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
        if (!head) return nullptr;
        ListNode* cur = head;
        if (head->next) {
            cur = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;
        return cur;
    }
};