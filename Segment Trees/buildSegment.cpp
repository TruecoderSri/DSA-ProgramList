#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;

int a[N], tree[4 * N];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[end];
        return;
    }

    int mid = (start + end) >> 1;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int st, int end, int l, int r)
{
    //  No Overlapping
    if (r < st || l > end)
    {
        // return 0;
        return INT_MIN;
    }
    // Complete Overlapping
    if (l <= st && end <= r)
    {
        return tree[node];
    }
    // Partial Overlapping
    int mid = (st + end) >> 1;
    int left = query(2 * node, st, mid, l, r);
    int right = query(2 * node + 1, mid + 1, end, l, r);

    return max(left, right);
}

void update(int node, int st, int end, int idx, int val)
{
    if (st == end)
    {
        a[st] = val;
        tree[node] = val;
        return;
    }
    int mid = (st + end) >> 1;
    if (idx <= mid)
    {
        update(2 * node, st, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main()

{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    build(1, 0, n - 1);

    for (int i = 1; i < 2 * n - 1; i++)
    {
        cout << tree[i] << "\t";
    }
    cout << endl;
    while (1)
    {
        int type;
        cin >> type;
        if (type == -1)
            break;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << ans << endl;
        }
        if (type == 2)
        {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
            cout << query(1, 0, n - 1, 0, n - 1) << endl;
        }
    }
    return 0;
}