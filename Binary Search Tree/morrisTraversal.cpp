vector<int> morrisTraversal(Node *root)
{

    vector<int> ans;
    Node *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            // update the prev element
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            // make a connection b/w the right leaf and the root element
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            // we go to the right to explore more
            else
            {
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

vector<int> optimisedTraversal(Node *root)
{
    vectir<int> ans;
    morristraversal(root, ans);
    return ans;
}