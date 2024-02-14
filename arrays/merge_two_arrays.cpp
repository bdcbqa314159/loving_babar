#include <iostream>
#include <vector>

void merge_arrays(std::vector<int> &v1, std::vector<int> &v2, std::vector<int> &output)
{
    int n = v1.size(), m = v2.size();
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (v1[i] < v2[j])
        {
            output[k] = v1[i];
            i++;
        }
        else
        {
            output[k] = v2[j];
            j++;
        }
        k++;
    }

    while (i < n)
    {
        output[k] = v1[i];
        i++;
        k++;
    }

    while (j < m)
    {
        output[k] = v2[j];
        j++;
        k++;
    }
}

int main()
{

    std::vector<int> arr1 = {1, 3, 5, 7};

    std::vector<int> arr2 = {2, 4, 6, 8};

    int m = arr1.size() + arr2.size();

    std::vector<int> output(m);
    merge_arrays(arr1, arr2, output);

    std::cout << "Array after merging" << std::endl;
    for (int i = 0; i < m; i++)
        std::cout << output[i] << " ";

    return 0;
}
