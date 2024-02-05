#include <iostream>
#include <vector>
#include <algorithm>

const char nl = '\n';

void print(const std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector.at(i) << nl;
    }
    return;
}

std::vector<int> getUnion(const std::vector<int> &a, const std::vector<int> &b)
{
    size_t index = 0, left = 0, right = 0, n = a.size(), m = b.size();
    std::vector<int> result(n + m);

    while (left < n && right < m)
    {
        if (a.at(left) < b.at(right))
        {
            if (index != 0 && a.at(left) == result.at(index - 1))
                left++;
            else
            {
                result.at(index) = a.at(left);
                left++;
                index++;
            }
        }
        else
        {
            if (index != 0 && b.at(right) == result.at(index - 1))
                right++;
            else
            {
                result.at(index) = b.at(right);
                right++;
                index++;
            }
        }
    }

    while (left < n)
    {
        if (index != 0 && a.at(left) == result.at(index - 1))
            left++;
        else
        {
            result.at(index) = a.at(left);
            left++;
            index++;
        }
    }
    while (right < m)
    {
        if (index != 0 && b.at(right) == result.at(index - 1))
            right++;
        else
        {
            result.at(index) = b.at(right);
            right++;
            index++;
        }
    }
    return result;
}

std::vector<int> intersection(const std::vector<int> &a, const std::vector<int> &b)
{
    size_t i{}, j{}, k{}, n = a.size(), m = b.size();
    std::vector<int> result(std::min(n, m));
    while (i < n && j < m)
    {
        if (a.at(i) < b.at(j))
            i++;
        else if (a.at(i) > b.at(j))
            j++;
        else
        {
            if (k != 0 && a[i] == result[k - 1])
            {
                i++;
                j++;
            }
            else
            {
                result[k] = a[i];
                i++;
                j++;
                k++;
            }
        }
    }
    return result;
}

int main()
{
    std::vector<int> a = {1, 3, 2, 3, 3, 4, 5, 5, 6};
    std::vector<int> b = {3, 3, 5};

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::vector<int> res_1 = getUnion(a, b);
    std::vector<int> res_2 = intersection(a, b);

    print(res_1);
    // print(res_2);

    return 0;
}