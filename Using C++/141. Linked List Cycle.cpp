/**
 * @brief First Solution
 * -- O(n)
 * -- Uses a hashmap to check if the pointer existed
 * -- Worst solution
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> nmap(false);
        while (head) {
            if (nmap[head] == true)
                return true;
            else {
                nmap[head] = true;
                head = head->next;
            }
        }
        return false;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Two-pointer technique, if both met, then there is a cycle, if one of them hits null, then no cycle
 * -- Best Solution
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};