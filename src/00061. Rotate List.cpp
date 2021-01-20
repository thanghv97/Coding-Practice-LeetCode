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
    ListNode* rotateRight(ListNode* head, int k) {
        std::vector<ListNode*> list;
        
        ListNode* p = head;
        while (p != nullptr) {
            list.push_back(p);
            p = p->next;
        }
        
        if (list.size() == 0) return head;
        int id = k % list.size();
        if (id != 0) {
            list[list.size() - 1]->next = head;
            list[list.size() - id - 1]->next = nullptr;
            head = list[list.size() - id];
        }
        return head;
    }
};