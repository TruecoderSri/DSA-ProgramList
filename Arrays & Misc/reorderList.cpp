#include <iostream>
#include <stack>
using namespace std;
// Definition for singly-linked list.
// time comp:O(N),space comp.=O(N)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *curr = head;
        while (curr)
        {
            st.push(curr);
            curr = curr->next;
        }
        int n = st.size();
        ListNode *ptr;
        curr = head;
        for (int i = 0; i < n / 2; i++)
        {
            ptr = curr->next;
            curr->next = st.top();
            st.pop();
            curr = curr->next;
            curr->next = ptr;
            curr = curr->next;
        }
        curr->next = NULL;
    }
};

// Alternate Approach
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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half of numbers to access them
        ListNode *curr = slow, *tmp, *prev = NULL;
        while (curr)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        ListNode *n1 = head, *n2 = prev;
        while (n2->next)
        {
            tmp = n1->next;
            n1->next = n2;
            n1 = tmp;

            tmp = n2->next;
            n2->next = n1;
            n2 = tmp;
        }
    }
};