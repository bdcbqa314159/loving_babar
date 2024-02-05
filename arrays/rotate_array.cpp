#include <iostream>
#include <vector>

const char nl = '\n';
void print(const std::vector<int> &vector)
{

    for (size_t i = 0; i < vector.size(); i++)
        std::cout << vector.at(i) << " ";
    std::cout << nl;
}

void rotate(std::vector<int> &vector, size_t k)
{
    size_t n = vector.size();
    if (k >= n)
        std::abort();

    for (size_t i = 0, j = n - k - 1; i < j; i++, j--)
        std::swap(vector.at(i), vector.at(j));

    for (size_t i = 0, j = n - 1; i < j; i++, j--)
        std::swap(vector.at(i), vector.at(j));
    return;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    std::cout << "before:" << nl;
    print(arr);
    rotate(arr, 1);
    std::cout << "after" << nl;
    print(arr);

    return 0;
}