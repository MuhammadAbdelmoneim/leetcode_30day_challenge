#include <iostream>
#include <vector>
#include <algorithm>


int maxProfit(std::vector<int>& prices) {
        if(!prices.size())
            return 0;
        int profit = 0;
        for(auto i = 0; i < prices.size() - 1;++i)
        {
            if(prices[i] < prices[i + 1])
            {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
}



int main(void)
{
    std::vector<int> v{7,1,5,3,6,4};
    int profit  = maxProfit(v);
    std::cout << profit << std::endl;

    return 0;
}
