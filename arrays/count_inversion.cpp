#include <iostream>
#include <vector>

int merge(std::vector<int> &array, std::vector<int> &temp, int left, int mid, int right)
{
    int i = left, j = mid, k = left;
    int inv_count{};
    while (i <= mid - 1 && j <= right)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        temp[k] = array[i];
        k++;
        i++;
    }

    while (j <= right)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++)
        array[i] = temp[i];
    return inv_count;
}

int helper(std::vector<int> &array, std::vector<int> &temp, int l, int r)
{
    int mid{}, inv_count{};
    if (r > l)
    {
        mid = l + (r - l) / 2;

        inv_count += helper(array, temp, l, mid);
        inv_count += helper(array, temp, mid + 1, r);

        inv_count += merge(array, temp, l, mid + 1, r);
    }
    return inv_count;
}

int merge_sort(std::vector<int> &array)
{
    int N = array.size();
    std::vector<int> temp(N);
    return helper(array, temp, 0, N - 1);
}

int main()
{
    std::vector<int> arr = {1, 20, 6, 4, 5};

    int ans = merge_sort(arr);
    std::cout << " Number of inversions are " << ans << std::endl;
    return 0;
}