/**
 * @brief First Solution
 * -- Time Complexity: O(n)
 * -- Space Complexity: O(1)
 * -- Find the middle, reverse the second half, merge the two lists
 */
class Solution {
public:

    ListNode* reverselist(ListNode* head) {
        
        if (!head) return nullptr;
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* nNode = nullptr;
        while (current) {
            nNode = current->next; current->next = prev;
            prev = current; current = nNode;
        }
        return prev;
    }
    
    void merge(ListNode* list1, ListNode* list2) {

        while (list2) {
            ListNode* nNode = list1->next;
            list1->next = list2;
            list1 = list2; list2 = nNode;
        }
    }

    void reorderList(ListNode* head) {
        
        if (!head || !head->next) return;
        ListNode* dummy = head;
        ListNode* middle = head;
        ListNode* finaly = head;
        while (finaly && finaly->next) {
            dummy = middle;
            finaly = finaly->next->next;
            middle = middle->next;
        }
        dummy->next = nullptr;
        ListNode* list1 = head;
        ListNode* list2 = reverselist(middle);
        merge(list1, list2);
    }
};