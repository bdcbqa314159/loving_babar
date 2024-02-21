#include <iostream>
#include <vector>

using namespace std;

int max_product(vector<int> &arr)
{
    int n = arr.size();
    int maxVal = arr[0], minVal = arr[0], maxProduct = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            swap(maxVal, minVal);

        maxVal = max(arr[i], maxVal * arr[i]);
        minVal = min(arr[i], minVal * arr[i]);
        maxProduct = max(maxProduct, maxVal);
    }

    return maxProduct;
}

int main()
{

    vector<int> arr = {-1, -3, -10, 0, 60};

    cout << "Maximum Subarray product is "
         << max_product(arr) << endl;

    return 0;
}
