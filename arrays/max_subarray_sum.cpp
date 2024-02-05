#include <vector>
#include <iostream>

const char nl = '\n';

void print(const std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector.at(i) << nl;
    }
    return;
}

int max_subarray_sum(const std::vector<int> &vector)
{
    size_t n = vector.size();
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (size_t i = 0; i < n; i++)
    {
        max_ending_here += vector.at(i);
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    std::vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    int answer = max_subarray_sum(arr);

    std::cout << "answer is 7? " << answer << nl;

    return 0;
}