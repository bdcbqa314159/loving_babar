#include <iostream>
#include <vector>

int max_profit(std::vector<int> &prices)
{
    int buy = INT_MAX, max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (buy > prices[i])
            buy = prices[i];
        else
            max_profit = std::max(max_profit, prices[i] - buy);
    }
    return max_profit;
}

int main()
{

    std::vector<int> prices = {7, 1, 5, 6, 4};
    int value = max_profit(prices);
    std::cout << value << std::endl;

    return 0;
}
