#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    /**
     * @brief Visited Set
     * @details Stores visited nodes in a hash map, returns true if a node is revisited
     * @complexity: Time: O(n), Space: O(n)
     */
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> set;
        while (head)
        {
            if (set.count(head))
                return true;
            set.insert(head);
            head = head->next;
        }
        return false;
    }

    /**
     * @brief Floyd’s Tortoise and Hare algorithm
     * @details Uses two pointers moving at different speeds, returns true if they meet
     * @complexity: Time: O(n), Space: O(1)
     */
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};