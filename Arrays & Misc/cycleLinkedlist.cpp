#include <iostream>
using namespace std;
struct node
{
    int val;
    struct node *next;
};
bool checkCycle(node *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    node *slow = head;
    node *fast = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}
