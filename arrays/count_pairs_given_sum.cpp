#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int get_pairs_count(const vector<int> &input, int sum)
{
    unordered_map<int, int> the_map{};
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (the_map.find(sum - input[i]) != the_map.end())
            count += the_map[sum - input[i]];
        the_map[input[i]]++;
    }
    return count;
}

int main()
{

    vector<int> arr = {1, 5, 7, -1};
    int sum = 6;

    // Function Call
    cout << "Count of pairs is " << get_pairs_count(arr, sum) << endl;
    return 0;
}