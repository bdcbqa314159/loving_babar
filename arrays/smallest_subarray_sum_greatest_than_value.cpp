#include <iostream>
#include <vector>

using namespace std;

int smallest_sub_array_with_sum_bigger_than(int target, vector<int> &arr)
{
    int n = arr.size();
    int curr_sum{}, min_len = n + 1;
    int start{}, end{};

    while (end < n)
    {
        while (curr_sum <= target && end < n)
        {
            curr_sum += arr[end];
            end++;
        }
        while (curr_sum > target && start < n)
        {
            if (end - start < min_len)
                min_len = end - start;
            curr_sum -= arr[start];
            start++;
        }
    }

    return min_len;
}

int main()
{
    vector<int> arr1 = {1, 4, 45, 6, 10, 19};
    int x = 51;

    int res1 = smallest_sub_array_with_sum_bigger_than(x, arr1);
    (res1 == arr1.size() + 1) ? cout << "Not possible\n"
                              : cout << res1 << endl;

    vector<int> arr2 = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    x = 9;
    int res2 = smallest_sub_array_with_sum_bigger_than(x, arr2);
    (res2 == arr2.size() + 1) ? cout << "Not possible\n"
                              : cout << res2 << endl;

    vector<int> arr3 = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    x = 280;
    int res3 = smallest_sub_array_with_sum_bigger_than(x, arr3);
    (res3 == arr3.size() + 1) ? cout << "Not possible\n"
                              : cout << res3 << endl;

    return 0;
}