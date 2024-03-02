#include <iostream>
#include <vector>

using namespace std;

int max_water(vector<int> &input)
{
    int n = input.size();

    int left = 0, right = n - 1;
    int l_max = 0, r_max = 0;

    int result = 0;

    while (left <= right)
    {
        if (r_max <= l_max)
        {
            result += max(0, r_max - input[right]);
            r_max = max(r_max, input[right]);
            right -= 1;
        }

        else
        {

            result += max(0, l_max - input[left]);
            l_max = max(l_max, input[left]);
            left += 1;
        }
    }

    return result;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << max_water(arr) << endl;

    return 0;
}