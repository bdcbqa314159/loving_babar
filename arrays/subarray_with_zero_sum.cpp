#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool subarray_exists(vector<int> &input)
{

    unordered_set<int> sum_set{};
    int sum{}, N = input.size();

    for (int i = 0; i < N; i++)
    {
        sum += input[i];

        if (sum == 0 || sum_set.find(sum) != sum_set.end())
            return true;

        sum_set.insert(sum);
    }

    return false;
}

int main()
{
    vector<int> arr = {-3, 2, 3, 1, 6};

    // Function call
    if (subarray_exists(arr))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    cout << endl;

    return 0;
}