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

template <typename T>
struct Pair
{
    T min{}, max{};

    void set(const T &a, const T &b)
    {
        if (a < b)
        {
            min = a;
            max = b;
        }
        else
        {
            min = b;
            max = a;
        }
    }
};

template <typename T, size_t N>
Pair<T> get_min_max(const std::array<T, N> &array, size_t left, size_t right)
{
    size_t mid{};
    Pair<T> min_max, min_max_l, min_max_r;

    if (left == right || right == left + 1)
    {
        min_max.set(array[left], array[right]);
        return min_max;
    }

    mid = left + (right - left) / 2;

    min_max_l = get_min_max(array, left, mid);
    min_max_r = get_min_max(array, mid + 1, right);

    T a = std::max<T>(min_max_l.max, min_max_r.max);
    T b = std::min<T>(min_max_l.min, min_max_r.min);

    min_max.set(a, b);
    return min_max;
}

int main()
{
    std::array<int, 6> array = {1000, 11, 445, 1, 330, 3000};

    Pair<int> minmax = get_min_max<int>(array, 0, array.size() - 1);

    std::cout << "Minimum element is " << minmax.min << std::endl;
    std::cout << "Maximum element is " << minmax.max << std::endl;

    return 0;
}