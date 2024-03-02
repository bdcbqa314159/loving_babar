#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void appears_more_than_n_by_k(vector<int> &input, int k)
{
    int ratio = input.size() / k;
    unordered_map<int, int> freq;

    for (int i = 0; i < input.size(); i++)
    {
        freq[input[i]]++;
    }

    for (auto element : freq)
    {
        if (element.second > ratio)
            cout << element.first << " ";
    }
    cout << endl;

    return;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
    int n = arr.size();
    int k = 4;

    appears_more_than_n_by_k(arr, k);

    return 0;
}