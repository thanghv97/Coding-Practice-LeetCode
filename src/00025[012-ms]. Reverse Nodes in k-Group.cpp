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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode** pp = &head;
        
        while (true) {
            ListNode* begin = *pp, *a, *b;
            a = *pp;
            int i = 1;

            while (i < k) {
                b = begin->next;
                if (b == nullptr) {
                    begin = a;

                    while (i > 1) {
                        b = begin->next;
                        begin->next = b->next;
                        b->next = a;
                        a = b;
                        i--;
                    }
                    
                    return head;                
                }

                begin->next = b->next;
                b->next = a;
                a = b;

                i++;
            }
            *pp = a;

            if (begin->next == nullptr) {
                return head;
            }
            pp = &(begin->next);
        }

        return head;
    }
};