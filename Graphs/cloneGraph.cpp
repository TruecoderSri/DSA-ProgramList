// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
// */

// class Solution {
// public:

// // curr represents the curr node of the cloned list
// // node the curr of Original List
//     void dfs(Node* node,Node *curr,vector<Node*> &vis){
//         vis[curr->val]=curr;
//         for(auto ele:node->neighbors){
//             if(vis[ele->val]==NULL){
//                 Node *fresh=new Node(ele->val);
//                 (curr->neighbors).push_back(fresh);
//                 dfs(ele,fresh,vis);
//             }
//             (curr->neighbors).push_back(vis[ele->val]);
//         }
//     }
//     Node* cloneGraph(Node* node) {

//        if(node==NULL)
//        return NULL;

//        vector<Node*> vis(1000,NULL);
//        Node *copy=new Node(node->val);
//        vis[node->val]=copy;
//        for(auto curr:node->neighbors){
//            if(vis[curr->val]==NULL){
//                Node *newNode=new Node(curr->val);
//                (copy->neighbors).push_back(newNode);
//                dfs(curr,newNode,vis);
//            }
//            (copy->neighbors).push_back(vis[curr->val]);
//        }
//        return copy;
//     }
// };

class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
* /

    class Solution
{
    void dfs(Node *curr, Node *node, vector<Node *> &visited)
    {
        // Node* copy = new Node(node->val);
        visited[node->val] = node;
        for (auto ele : curr->neighbors)
        {
            if (visited[ele->val] == NULL)
            {
                Node *newnode = new Node(ele->val);
                (node->neighbors).push_back(newnode);
                dfs(ele, newnode, visited);
            }
            else
                (node->neighbors).push_back(visited[ele->val]);
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        vector<Node *> visited(1000, NULL);
        Node *copy = new Node(node->val);
        visited[node->val] = copy;
        // Iterate for all neighbors of the original list
        for (auto curr : node->neighbors)
        {
            if (visited[curr->val] == NULL)
            {
                Node *newnode = new Node(curr->val);
                // push the values to the cloned Nodes
                (copy->neighbors).push_back(newnode);
                dfs(curr, newnode, visited);
            }
            else
                (copy->neighbors).push_back(visited[curr->val]);
        }
        return copy;
    }
};
