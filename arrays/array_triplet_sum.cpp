#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool find_triplet(vector<int> &input, int sum)
{

    int n = input.size();
    for (int i = 0; i < n - 2; i++)
    {
        unordered_set<int> numbers{};

        int curr_sum = sum - input[i];
        for (int j = i + 1; j < n; j++)
        {
            int required_value = curr_sum - input[i];
            if (numbers.find(required_value) != numbers.end())
            {
                std::cout << "found: " << input[i] << " " << input[j] << " " << required_value << endl;
                return true;
            }

            numbers.insert(input[j]);
        }
    }
    return false;
}

int main()
{
    vector<int> A = {1, 4, 45, 6, 10, 8};
    int sum = 22;

    // Call the find3Numbers function to find and print the
    // triplet, if it exists
    find_triplet(A, sum);

    return 0;
}