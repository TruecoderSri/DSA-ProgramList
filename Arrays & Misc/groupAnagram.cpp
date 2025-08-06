#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<vector<string>> groupAnagram(vector<string> &str)
{
    map<vector<int>, vector<string>> mymap;
    int i;
    vector<vector<string>> result;
    for (auto i : str)
    {
        vector<int> count(26, 0);
        for (char c : i)
        {
            count[c - 'a']++;
        }
        mymap[count].emplace_back(i);
    }
    for (auto itr = mymap.begin(); itr != mymap.end(); itr++)
    {
        result.emplace_back(itr->second);
    }
    return result;
}
int main()
{
    string temp;
    // vector<vector<string>> s;
    vector<string> str;
    for (int i = 0; i < 6; i++)
    {
        cin >> temp;
        str.push_back(temp);
    }
    // s.push_back(str);
    groupAnagram(str);
    for (auto itr = str.begin(); itr != str.end(); itr++)
    {
        cout << (*itr) << "\t";
    }
    return 0;
}