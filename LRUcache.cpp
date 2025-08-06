//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    map<int, int> m;
    map<int, list<int>::iterator> add;
    list<int> l;
    int size;
    int capacity;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
        size = 0;
    }

    // Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if (m.find(key) != m.end())
        {
            list<int>::iterator it = add[key];
            l.erase(it);
            add.erase(key);
            m.erase(key);
            l.push_front(key);
            add[key] = l.begin();
            return m[key];
        }
        return -1;
    }

    // Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if (m.find(key) != m.end())
        {
            l.erase(add[key]);
            add.erase(key);
            m.erase(key);
            size--;
        }
        if (size == capacity)
        {
            int last = l.back();
            l.pop_back();
            add.erase(last);
            m.erase(last);
            size--;
        }
        size++;
        l.push_front(key);
        add[key] = l.begin();
        m[key] = value;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends