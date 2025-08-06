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
class Solution
{
public:
    struct compare
    {
        bool operator()(struct ListNode *a, struct ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (int i = 0; i < lists.size(); i++)
        {
            q.push(lists[i]);
        }
        ListNode *dummy = new ListNode();
        ListNode *last = dummy;
        while (!q.empty())
        {
            ListNode *curr = q.top();
            q.pop();
            last->next = curr;
            last = curr;
            if (curr->next)
                q.push(curr->next);     // denotes in the current vector of which the element is a part , if more element exists we add it in pq
        }
        return dummy->next;
    }
};