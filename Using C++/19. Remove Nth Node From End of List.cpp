/**
 * @brief First Solution
 * --> O(n)
 * --> Two-pointer technique
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *left = dummy;
        ListNode *right = head;

        while (n > 0 && right)
        {
            right = right->next;
            n--;
        }

        while (right)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;
    }
};