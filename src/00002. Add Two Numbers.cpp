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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* p = new ListNode(0);
        int tmp = 0;
        
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;
            if (l1 == nullptr) {
                sum = l2->val + tmp;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                sum = l1->val + tmp;
                l1 = l1->next;
            } else {
                sum = l1->val + l2->val + tmp;
                l2 = l2->next;
                l1 = l1->next;
            }
            
            p->next = new ListNode(sum % 10);
            tmp = sum / 10;
            p = p->next;
            if (head == nullptr) {
                head = p;
            }
        }
        
        if (tmp > 0) {
            p->next = new ListNode(1);
        }
        
        return head;
    }
};