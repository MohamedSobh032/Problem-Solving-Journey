/**
 * @brief First/Only Solution
 * -- O(n)
 * -- Get the next item, point to the pervious, move to the next item
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // condition check
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};