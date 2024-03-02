#include <iostream>
#include <vector>

using namespace std;

int upper_bound_position(vector<int> &arr1, vector<int> &arr2, int value)
{

    return upper_bound(arr1.begin(), arr1.end(), value) - arr1.begin() + upper_bound(arr2.begin(), arr2.end(), value) - arr2.begin();
}

double get_median(vector<int> &arr1, vector<int> &arr2)
{
    int limit = 1000000000;
    int low = -limit, high = limit;
    int pos = arr1.size();

    double ans{};

    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        int ub = upper_bound_position(arr1, arr2, mid);

        if (ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
    pos--;
    ans = static_cast<double>(low);
    low = -limit;
    high = limit;

    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);

        int ub = upper_bound_position(arr1, arr2, mid);

        if (ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
    ans = (ans + low) / 2.;
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 4, 5, 6, 10};
    vector<int> arr2 = {2, 3, 4, 5, 7};

    double median = get_median(arr1, arr2);

    cout << "Median is " << median << endl;

    return 0;
}