/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Finding the value by getting the next node value, then doing a while to handle the case of multiple values in a row.
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return nullptr;

        ListNode *ans = new ListNode(0, head);
        ListNode *iterator = ans;
        while (iterator)
        {
            while (iterator->next && iterator->next->val == val)
                iterator->next = iterator->next->next;
            iterator = iterator->next;
        }
        return ans->next;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Recursive solution, if the head value is equal to the value, then return the next node, else return the head node.
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return nullptr;

        if (head->val == val)
            return removeElements(head->next, val);
        else
        {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
};