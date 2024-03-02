#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

bool is_palindrome(int N)
{
    string str = to_string(N);

    int l = 0, r = str.size() - 1;
    while (l < r)
    {
        if (str[l] != str[r])
            return false;
        l++;
        r--;
    }
    return true;
}

bool is_palindrome_array(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (!is_palindrome(arr[i]))
            return false;
    }
    return true;
}

int main()
{
    int n = 12, m = 12344321;

    cout << "is " << n << " palindrome: " << is_palindrome(n) << endl;
    cout << "is " << m << " palindrome: " << is_palindrome(m) << endl;

    vector<int> arr = {121, 131, 20};

    bool res = is_palindrome_array(arr);
    if (res == true)
        cout << "Array is a PalinArray";
    else
        cout << "Array is not a PalinArray";
    cout << endl;

    return 0;
}