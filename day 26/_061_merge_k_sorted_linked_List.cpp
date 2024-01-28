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
    class compare {
    public:
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq; // minheap

        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;

        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            // cout<<curr->val<<endl;
            if (curr->next) { // cout<<"inserting "<<curr->next->val<<endl;
                pq.push(curr->next);
            }
            curr->next = NULL;
        }

        ans = ans->next;
        return ans;
    }
};