#include <iostream>
using namespace std;
// Time complexity is of O(N^3)
int find_palindromes_in_sub_string(const string &input, int l, int r)
{
    int count = 0;
    while (l >= 0 && r < input.size() && input[l] == input[r])
    {
        cout << input.substr(l, r - l + 1) << "\t";
        count++;
        l--;
        r++;
    }
    return count;
}

int find_all_palindrome_substrings(const string &input)
{
    int count = 0;
    for (int i = 0; i < input.length(); ++i)
    {
        count += find_palindromes_in_sub_string(input, i, i);
        count += find_palindromes_in_sub_string(input, i, i + 1);
    }
    return count;
}

int main()
{
    string str = "aaa";

    cout << "Total palindrome substrings: " << find_all_palindrome_substrings(str) << endl;
}