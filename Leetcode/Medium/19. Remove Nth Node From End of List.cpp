#include <vector>

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
     * @brief Store all nodes in an array, play with index
     * @details uses extra vector space to store nodes, then removes the (n-th from end) by index
     * @complexity: Time: O(n), Space: O(n)
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head || !head->next)
            return nullptr;

        std::vector<ListNode *> vec;
        ListNode *beg = head;
        while (beg)
        {
            vec.push_back(beg);
            beg = beg->next;
        }

        int indx = vec.size() - n;
        if (indx == 0)
            head = vec[indx + 1];
        else if (indx == vec.size() - 1)
            vec[indx - 1]->next = nullptr;
        else
            vec[indx - 1]->next = vec[indx + 1];

        return head;
    }

    /**
     * @brief Two Pointers (Fast and Slow)
     * @details advances one pointer n steps ahead, then moves both until fast reaches end, so slow stops before node to delete
     * @complexity: Time: O(n), Space: O(1)
     */
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *result = new ListNode(0, head);
        ListNode *dummy = result;

        for (int i = 0; i < n; i++)
            head = head->next;

        while (head)
        {
            head = head->next;
            dummy = dummy->next;
        }

        dummy->next = dummy->next->next;
        return result->next;
    }
};
