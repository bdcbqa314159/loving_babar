#include <iostream>
#include <vector>

using namespace std;

void three_way_partition(vector<int> &arr, int low, int high)
{
    int n = arr.size();
    int start{}, end = n - 1;
    int i = 0;

    while (i <= end)
    {
        if (arr[i] < low)
        {
            if (i == start)
            {
                start++;
                i++;
            }
            else
            {
                swap(arr[i], arr[start]);
                i++;
                start++;
            }
        }
        else if (arr[i] > high)
        {
            swap(arr[i], arr[end]);
            end--;
        }
        else
            i++;
    }
    return;
}

int main()
{
    vector<int> arr1 = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};

    three_way_partition(arr1, 10, 20);

    cout << "Modified array \n";
    for (int i = 0; i < arr1.size(); i++)
        cout << arr1[i] << " ";
    cout << endl;

    return 0;
}