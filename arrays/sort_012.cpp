#include <iostream>
#include <array>

template <typename Array>
void sorting_012(Array &array)
{
    size_t N = array.size(), l = 0, r = N - 1;
    for (size_t i = 0; i < N && i <= r;)
    {
        if (array[i] == 0)
        {
            std::swap(array[l], array[i]);
            l++;
            i++;
        }

        else if (array[i] == 2)
        {
            std::swap(array[i], array[r]);
            r--;
        }

        else
            i++;
    }

    return;
}

template <typename Array>
void print(const Array &array)
{
    size_t N = array.size();
    for (size_t i = 0; i < N; i++)
        std::cout << array.at(i) << " ";
    std::cout << std::endl;
    return;
}

int main()
{
    std::array<int, 12> arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    std::cout << "Before:" << std::endl;
    print(arr);

    std::cout << "After:" << std::endl;
    print(arr);
    return 0;
}
