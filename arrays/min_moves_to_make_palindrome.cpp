#include <iostream>

using namespace std;

int minMovesToMakePalindrome(string s)
{
    int n = s.length();

    int left = 0, right = s.size() - 1, ans = 0;
    while (left < right)
    {
        int l = left, r = right;
        while (s[l] != s[r])
            r--;
        if (l == r)
        {
            // here we hit the odd element
            swap(s[r], s[r + 1]);
            ans++;
            continue;
        }
        else
        {
            // normal element
            while (r < right)
                swap(s[r], s[r + 1]), ans++, r++;
        }
        left++, right--;
    }
    return ans;
}

int main()
{
    string s1 = "letelt";
    string s2 = "aabb";
    cout << "for " << s1 << " we have " << minMovesToMakePalindrome(s1) << endl;
    cout << "for " << s2 << " we have " << minMovesToMakePalindrome(s2) << endl;

    return 0;
}