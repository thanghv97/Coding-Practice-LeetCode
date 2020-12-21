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
    struct comparer {
        inline bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparer> heap;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                heap.push(lists[i]);
            }
        }
        if (heap.empty()) {
            return nullptr;
        }
        
        ListNode* head = heap.top();
        heap.pop();
        if (head->next) {
            heap.push(head->next);
        }        
        
        ListNode* p = head;
        while (heap.size() > 0) {
            p->next = heap.top();
            heap.pop();
            p = p->next;
            if (p->next) {
                heap.push(p->next);
            }
        }
        return head;
    }
};