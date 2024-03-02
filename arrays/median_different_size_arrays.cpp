#include <iostream>
#include <vector>

using namespace std;

double get_median(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    if (n > m)
        return get_median(b, a);

    int start = 0, end = n;
    int real_mid_in_merged_array = (n + m + 1) / 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int left_a_size = mid;
        int left_b_size = real_mid_in_merged_array - mid;

        int leftA = left_a_size > 0 ? a[left_a_size - 1] : INT_MIN;
        int leftB = left_b_size > 0 ? b[left_b_size - 1] : INT_MIN;

        int rightA = left_a_size < n ? a[left_a_size] : INT_MAX;
        int rightB = left_b_size < m ? b[left_b_size] : INT_MAX;

        if (leftA <= rightB && leftB <= rightA)
        {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.;
            else
                return max(leftA, leftB);
        }

        else if (leftA > rightB)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return 0.;
}

int main()
{
    vector<int> arr1 = {-5, 3, 6, 12, 15};
    vector<int> arr2 = {-12, -10, -6, -3, 4, 10};
    cout << "Median of the two arrays are" << endl;
    cout << get_median(arr1, arr2) << endl;

    return 0;
}