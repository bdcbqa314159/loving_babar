#include <iostream>
#include <vector>
#include <algorithm>

const char nl = '\n';

int getMinDiff(const std::vector<int> &input, int k)
{

    std::vector<int> temp = input;
    std::sort(temp.begin(), temp.end());
    size_t n = input.size();
    int ans = temp[n - 1] - temp[0], temp_min = temp[0], temp_max = ans;

    for (size_t i = 0; i < n; i++)
    {
        if (temp[i] - k < 0)
            continue;

        temp_min = std::min(temp[0] + k, temp[i] - k);
        temp_max = std::max(temp[i - 1] + k, temp[0] - k);

        ans = std::min(ans, temp_max - temp_min);
    }
    return ans;
}

int main()
{
    int k = 6, n = 6;
    std::vector<int> ans = {7, 4, 8, 8, 8, 9};

    // Function Call
    int response = getMinDiff(ans, k);

    std::cout << response << nl;

    return 0;
}