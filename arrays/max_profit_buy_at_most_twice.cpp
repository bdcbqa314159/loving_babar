#include <iostream>
#include <vector>

using namespace std;

int maxTwoBuyToSell(vector<int> &input)
{
    int first_buy = INT_MIN, first_sell = 0;
    int second_buy = INT_MIN, second_sell = 0;

    for (int i = 0; i < input.size(); i++)
    {
        first_buy = max(first_buy, -input[i]);
        first_sell = max(first_sell, first_buy + input[i]);
        second_buy = max(second_buy, first_sell - input[i]);
        second_sell = max(second_sell, second_buy + input[i]);
    }
    return second_sell;
}

int main()
{
    vector<int> arr = {2, 30, 15, 10, 8, 25, 80};
    cout << maxTwoBuyToSell(arr) << endl;

    return 0;
}