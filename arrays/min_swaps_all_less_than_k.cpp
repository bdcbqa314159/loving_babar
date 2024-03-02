#include <iostream>
#include <vector>

using namespace std;

int min_swaps(vector<int> &arr, int k)
{
    int snow_ball_size{}, n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            snow_ball_size++;
    }

    int swap{}, ans_swaps = INT_MAX;
    for (int i = 0; i < snow_ball_size; i++)
    {
        if (arr[i] > k)
            swap++;
    }

    ans_swaps = min(swap, ans_swaps);
    for (int i = snow_ball_size; i < n; i++)
    {
        if (arr[i - snow_ball_size] <= k && arr[i] > k)
            swap++;
        else if (arr[i - snow_ball_size] > k && arr[i] <= k)
            swap--;
        ans_swaps = min(swap, ans_swaps);
    }

    return ans_swaps;
}

int main()
{
    vector<int> arr1 = {2, 7, 9, 5, 8, 7, 4};

    int k = 5;
    cout << min_swaps(arr1, k) << endl;

    return 0;
}