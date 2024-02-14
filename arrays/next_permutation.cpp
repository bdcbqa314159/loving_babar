#include <iostream>

void reverse(std::string &s, int l, int r)
{
    while (l < r)
    {
        std::swap(s[l], s[r]);
        l++;
        r--;
    }
}

int binary_search(std::string &input, int l, int r, int key)
{
    int index = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (input[mid] <= key)
            r = mid - 1;
        else
        {
            l = mid + 1;
            if (index == -1 || input[index] >= input[mid])
                index = mid;
        }
    }
    return index;
}

bool next_permutation(std::string &s)
{
    int l = s.length(), i = l - 2;

    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    if (i < 0)
        return false;
    else
    {
        int index = binary_search(s, i + 1, l - 1, s[i]);
        std::swap(s[i], s[index]);
        reverse(s, i + 1, l - 1);
        return true;
    }
}

int main()
{
    std::string s = {"gfg"};
    bool val = next_permutation(s);
    if (val == false)
        std::cout << "No Word Possible" << std::endl;
    else
        std::cout << s << std::endl;
    return 0;
}
