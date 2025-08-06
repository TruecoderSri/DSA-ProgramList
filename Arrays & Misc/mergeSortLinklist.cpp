//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    void Findmiddle(Node *curr, Node **first, Node **second)
    {
        Node *fast = curr;
        Node *slow = curr;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        *first = curr;
        *second = slow->next;
        slow->next = NULL;
    }

    void merged(Node **head)
    {
        Node *curr = *head;
        Node *first;
        Node *second;
        if (!curr || !curr->next)
        {
            return;
        }

        Findmiddle(curr, &first, &second);

        merged(&first);

        merged(&second);

        *head = mergedBoth(first, second);
    }

    Node *mergedBoth(Node *first, Node *second)
    {
        Node *answer = NULL;
        if (!first)
            return second;
        else if (!second)
            return first;

        if (first->data <= second->data)
        {
            answer = first;
            answer->next = mergedBoth(first->next, second);
        }
        else
        {
            answer = second;
            answer->next = mergedBoth(first, second->next);
        }
        return answer;
    }

    // Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        // your code here
        merged(&head);
        return head;
    }
};

//{ Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends