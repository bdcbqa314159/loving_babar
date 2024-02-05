#include <iostream>
#include <vector>
#include <algorithm>

const char nl = '\n';

int getMinDifference(std::vector<int> &array, int k)
{
    std::sort(array.begin(), array.end());
    size_t n = array.size();

    int ans = array.at(n - 1) - array.at(0);
    int tempmin = array.at(0), tempmax = array.at(n - 1);

    for (size_t i = 1; i < n; i++)
    {

        if (array.at(i) - k < 0)
            continue;

        tempmin = std::min(array.at(0) + k, array.at(i) - k);
        tempmax = std::max(array.at(i - 1) + k, array.at(n - 1) - k);

        ans = std::min(ans, tempmax - tempmin);
    }
    return ans;
}

int main()
{
    std::vector<int> array = {1, 5, 15, 10};
    int answer = getMinDifference(array, 3);

    std::cout << "Answer should be 8: " << answer << nl;

    return 0;
}