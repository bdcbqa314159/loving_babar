#include <iostream>
#include <array>

template <typename Array>
size_t partition(Array &array, size_t l, size_t r)
{
    int x = array.at(r);
    size_t i = l;
    for (size_t j = l; j < r; j++)
    {
        if (array.at(j) < x)
        {
            std::swap(array.at(i), array.at(j));
            i++;
        }
    }

    std::swap(array.at(r), array.at(i));

    return i;
}

template <typename Array>
size_t randomPartition(Array &array, size_t l, size_t r)
{
    size_t n = r - l + 1;
    size_t pivot = static_cast<size_t>(std::rand()) % n;
    std::swap(array[pivot], array[r]);
    return partition<Array>(array, l, r);
}

template <typename Array>
typename Array::value_type kth_smallest(Array &array, size_t l, size_t r, size_t K)
{
    size_t pos = partition<Array>(array, l, r);
    // size_t pos = randomPartition<Array>(array, l, r);
    if (pos == K - 1)
    {
        return array.at(pos);
    }

    else if (K - 1 < pos)
    {
        return kth_smallest(array, l, pos - 1, K);
    }

    else
    {
        return kth_smallest(array, pos + 1, r, K);
    }
}

int main()
{
    std::array<int, 7> array = {12, 3, 5, 7, 4, 19, 26};
    size_t N = array.size();

    for (size_t K = 1; K <= N; K++)
        std::cout << "K'th smallest element is " << kth_smallest(array, 0, N - 1, K) << std::endl;

    return 0;
};