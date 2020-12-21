/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* p = new ListNode(0);
        
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                p->next = new ListNode(l2->val);
                l2 = l2->next;
            } else if (l2 == nullptr) {
                p->next = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                if (l1->val < l2->val) {
                    p->next = new ListNode(l1->val);
                    l1 = l1->next;
                } else {
                    p->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
            }
            
            p = p->next;
            if (head == nullptr) {
                head = p;
            }
        }
        return head;
    }
};