#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void right_rotate(vector<int> &arr, int out_of_place, int curr)
{
    int temp = arr[curr];
    for (int i = curr; i > out_of_place; i--)
        arr[i] = arr[i - 1];
    arr[out_of_place] = temp;
    return;
}

void rearrange(vector<int> &arr)
{
    int out_of_place = -1;
    for (int index = 0; index < arr.size(); index++)
    {
        if (out_of_place >= 0)
        {
            if ((arr[index] >= 0 && arr[out_of_place] < 0) || (arr[index] < 0 && arr[out_of_place] >= 0))
            {
                right_rotate(arr, out_of_place, index);
                if (index - out_of_place >= 2)
                    out_of_place += 2;
                else
                    out_of_place = -1;
            }
        }

        else
        {
            if ((arr[index] >= 0 && index % 2 == 1) || (arr[index] < 0 && index % 2 == 0))
                out_of_place = index;
        }
    }
}

vector<int> rearrange_extra_space(const vector<int> &arr)
{
    int n = arr.size();
    queue<int> pos{}, neg{};

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push(arr[i]);
        }
        else
        {
            neg.push(arr[i]);
        }
    }

    vector<int> result(n);
    int i = 0;
    while ((!pos.empty()) && (!neg.empty()))
    {
        result[i] = pos.front();
        pos.pop();
        i++;
        result[i] = neg.front();
        neg.pop();
        i++;
    }
    while (!pos.empty())
    {
        result[i] = pos.front();
        pos.pop();
        i++;
    }

    while (!neg.empty())
    {
        result[i] = neg.front();
        neg.pop();
        i++;
    }

    return result;
}

int main()
{
    vector<int> arr = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};

    vector<int> result = rearrange_extra_space(arr);

    cout << "extra space: " << endl;
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    rearrange(arr);
    cout << "no extra space: " << endl;
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}