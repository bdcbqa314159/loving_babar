#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_subset(vector<int> &input1, vector<int> &input2)
{

    unordered_map<int, int> frequency{};

    for (int element : input1)
        frequency[element]++;

    for (int element : input2)
    {
        if (frequency[element] > 0)
            frequency[element]--;
        else
            return false;

        return true;
    }
}

int main()
{

    vector<int> arr1 = {11, 1, 13, 21, 3, 7};
    vector<int> arr2 = {11, 3, 7, 1};

    if (is_subset(arr1, arr2))
        cout << "arr2[] is subset of arr1[] "
             << "\n";
    else
        cout << "arr2[] is not a subset of arr1[] "
             << "\n";

    return 0;
}