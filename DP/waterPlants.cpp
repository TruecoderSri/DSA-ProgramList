int min_sprinklers(int gallery[], int n)
{
    vector<pair<int, int>> cover;

    for (int i = 0; i < n; i++)
    {
        if (gallery[i] == -1)
            cover.push_back(make_pair(1e7, 1e7));
        else
            cover.push_back(make_pair(i - gallery[i], i + gallery[i]));
    }

    sort(cover.begin(), cover.end());

    int take = 0, index = 0, ans = 0;

    while (take < n)
    {

        int curr_acquired = take - 1;

        // check whether the value we need to acquire is in the range of the current position or not

        while (index < n && cover[index].first <= take)
        {
            curr_acquired = max(curr_acquired, cover[index].second);
            index++;
        }

        if (curr_acquired + 1 > take)
        { // now we cover from the next position
            ans++;
            take = curr_acquired + 1;
        }
        else
            return -1;
    }

    return ans;
}