#include <iostream>
#include <vector>
#include <algorithm>

struct Interval
{
    int s{}, e{};
};

bool interval_comp(const Interval &a, const Interval &b)
{
    return a.s < b.s;
}

void merge_intervals(std::vector<Interval> &intervals)
{
    std::sort(intervals.begin(), intervals.end(), interval_comp);
    int n = intervals.size(), index = 0;

    for (int i = 1; i < n; i++)
    {
        if (intervals[index].e >= intervals[i].s)
            intervals[index].e = std::max(intervals[index].e, intervals[i].e);
        else
        {
            index++;
            intervals[index] = intervals[i];
        }
    }

    std::cout << "\n The Merged Intervals are: " << '\n';
    for (int i = 0; i <= index; i++)
        std::cout << "[" << intervals[i].s << ", " << intervals[i].e << "] ";
    std::cout << '\n';

    return;
}

int main()
{
    std::vector<Interval> arr = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    merge_intervals(arr);

    return 0;
}