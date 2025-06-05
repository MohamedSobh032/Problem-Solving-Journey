struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    /**
     * @brief Iterative Two-pointer
     * @details traverses the list while reversing the direction of the next pointers.
     * @complexity: Time: O(n), Space: O(1)
     */
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *ptr = head->next;
        ListNode *prev = head;
        while (ptr)
        {
            ListNode *temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        head->next = nullptr;
        return prev;
    }

    /**
     * @brief Recursion
     * @details recursively by unwinding the call stack and reversing pointers on the way back up.
     * @complexity: Time: O(n), Space: O(n) (due to recursion stack)
     */
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }
};