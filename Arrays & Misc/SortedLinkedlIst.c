//{ Driver Code Starts
#include <iostream>
using namespace std;

using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
// To print the sorted order of multiple iterations of 0s,1s & 2s
*/
class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        if (!head || !head->next)
            return head;

        Node *zero = new Node(0);
        Node *one = new Node(0);
        Node *two = new Node(0);

        Node *oneD = one;
        Node *zeroD = zero;
        Node *twoD = two;

        Node *curr = head;
        while (curr)
        {
            if (curr->data == 0)
            {
                zeroD->next = curr;
                zeroD = zeroD->next;
                curr = curr->next;
            }
            else if (curr->data == 1)
            {
                oneD->next = curr;
                oneD = oneD->next;
                curr = curr->next;
            }
            else
            {
                twoD->next = curr;
                twoD = twoD->next;
                curr = curr->next;
            }
        }
        zeroD->next = one->next ? one->next : two->next;
        oneD->next = two->next;
        twoD->next = NULL;

        head = zero->next;

        delete zero;
        delete one;
        delete two;

        return head;
    }
};

//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1)
{
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main()
{

    int n;

    int t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends