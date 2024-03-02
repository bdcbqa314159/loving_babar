#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int dfs(int start, unordered_map<int, int> &longest)
{
    if (longest.find(start) == longest.end())
        return 0;

    if (longest[start] != 0)
        return longest[start];

    int currentLongest = 1 + dfs(start + 1, longest);

    longest[start] = currentLongest;

    return currentLongest;
}

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() <= 1)
        return nums.size();

    int max_ = 1;
    unordered_map<int, int> longest;
    for (int n : nums)
    {
        longest[n] = 0;
    }

    for (int i = 0; i < nums.size(); i++)
        max_ = max(max_, dfs(nums[i], longest));

    return max_;
}

int main()
{
    vector<int> arr = {1, 9, 3, 10, 4, 20, 2};
    cout << "Length of the Longest consecutive subsequence is "
         << longestConsecutive(arr) << endl;

    return 0;
}