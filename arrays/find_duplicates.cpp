#include <iostream>
#include <vector>

const char nl = '\n';
std::vector<int> duplicates(std::vector<int> &input)
{

    int n = input.size();

    std::vector<int> output{};

    for (int i = 0; i < n; i++)
    {
        int index = input[i] % n;
        input[index] += n;
    }

    for (int i = 0; i < n; i++)
    {
        if (input[i] / n >= 2)
            output.push_back(i);
    }

    return output;
}

int main()
{

    std::vector<int> arr = {1, 6, 3, 1, 3, 6, 6};

    std::cout << "The repeating elements are: \n";

    // Function call
    std::vector<int> ans = duplicates(arr);
    for (auto x : ans)
        std::cout << x << " ";
    std::cout << nl;
    return 0;
}
