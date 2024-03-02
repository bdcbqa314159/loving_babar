#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_min_diff(vector<int> &arr, int m)
{
    int n = arr.size();
    if (m == 0 || n == 0)
        return 0;

    sort(arr.begin(), arr.end());

    if (n < m)
        return -1;

    int min_diff = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min_diff)
            min_diff = diff;
    }
    return min_diff;
}

int main()
{

    vector<int> arr = {12, 4, 7, 9, 2, 23, 25, 41, 30,
                       40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7; // Number of students

    cout << "Minimum difference is " << find_min_diff(arr, m) << endl;

    return 0;
}