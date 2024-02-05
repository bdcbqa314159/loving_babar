#include <iostream>
#include <array>

template <typename Array>
void print(const Array &array)
{
    size_t N = array.size();
    for (size_t i = 0; i < N; i++)
        std::cout << array.at(i) << " ";
    std::cout << std::endl;
    return;
}

template <typename Array>
void rearrange(Array &array)
{
    size_t l = 0, r = array.size() - 1;

    while (l < r)
    {
        if (array.at(l) < 0)
            l++;
        else if (array.at(r) > 0)
            r--;
        else
        {
            std::swap(array.at(l), array.at(r));
        }
    }
    return;
}

int main()
{
    std::array<int, 14> arr = {1, 2, -4, -5, 2, -7, 3, 2, -6, -8, -9, 3, 2, 1};

    std::cout << "Before:" << std::endl;
    print(arr);
    rearrange(arr);
    std::cout << "After:" << std::endl;
    print(arr);

    return 0;
}