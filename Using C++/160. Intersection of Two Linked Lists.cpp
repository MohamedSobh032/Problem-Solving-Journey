/**
 * @brief First Solution
 * -- Time Complexity: O(n + m)
 * -- Space Complexity: O(n)
 * -- Hashes the first list and then checks the second list for the first node that is in the hash map.
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        std::unordered_map<ListNode *, bool> nmap;
        ListNode *temp = headA;
        while (temp)
        {
            nmap[temp] = true;
            temp = temp->next;
        }
        temp = headB;
        while (temp)
        {
            if (nmap.find(temp) != nmap.end())
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

/**
 * @brief Second Solution
 * -- Time Complexity: O(n + m)
 * -- Space Complexity: O(1)
 * -- Using two-pointer technique, this method works because both pointers will have the same distance to the intersection node.
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != p2)
        {
            if (p1)
                p1 = p1->next;
            else
                p1 = headB;

            if (p2)
                p2 = p2->next;
            else
                p2 = headA;
        }
        return p1;
    }
};