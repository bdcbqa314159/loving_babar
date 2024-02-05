#include <iostream>
#include <array>

template <typename T, size_t N>
void print_array(const std::array<T, N> &array)
{
    for (size_t i = 0; i < N; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    return;
}

template <typename T, size_t N>
void reverse_array_iterative(std::array<T, N> &array)
{

    size_t i = 0, j = N - 1;

    while (i < j)
    {
        std::swap(array[i], array[j]);
        i++;
        j--;
    }
    return;
}

int main()
{
    std::cout << "Reverse array problem" << std::endl;

    std::array<int, 6> v = {1, 2, 3, 4, 5, 6};

    print_array(v);

    reverse_array_iterative(v);

    print_array(v);

    return 0;
}