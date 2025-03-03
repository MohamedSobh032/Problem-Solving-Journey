
/**
 * @brief First Solution
 * -- O(n)
 * -- Basic iterative
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *sorted = new ListNode();
        sorted->next = nullptr;
        ListNode *ret = sorted;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                sorted->next = list1;
                list1 = list1->next;
            }
            else
            {
                sorted->next = list2;
                list2 = list2->next;
            }
            sorted = sorted->next;
        }
        if (list1)
            sorted->next = list1;
        else
            sorted->next = list2;
        return ret->next;
    }
};

/**
 * @brief Second Solution
 * -- O(n)
 * -- Recursion
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};