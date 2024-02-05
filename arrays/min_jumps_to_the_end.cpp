#include <iostream>
#include <vector>
#include <algorithm>

const char nl = '\n';

int minJumps(std::vector<int> &array)
{
    size_t n = array.size();

    if (n <= 1)
        return 0;
    if (array.at(0) >= n - 1)
        return 1;
    if (array.at(0) == 0)
        return -1;

    int maxReach = array.at(0), step = array.at(0);
    int jump = 1;

    for (size_t i = 1; i < n; i++)
    {
        if (i == n - 1)
            return jump;
        if (array.at(i) >= n - 1 - i)
            return jump + 1;
        maxReach = std::max(maxReach, static_cast<int>(i) + array.at(i));
        step--;

        if (step == 0)
        {
            jump++;
            if (i >= maxReach)
                return -1;
            step = maxReach - i;
        }
    }

    return -1;
}

int main()
{
    std::vector<int> array = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    std::cout << "Answer should be 3 -> " << minJumps(array) << nl;

    return 0;
}