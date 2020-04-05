#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>




/* Kadane's Algorithm */
int maxSubArray(std::vector<int>& nums) {
    int max = nums[0];
    int currentMax = nums[0];
    for(auto i = 1; i < nums.size(); ++i)
    {
        if((nums[i] + currentMax) > nums[i])
        {
            currentMax += nums[i];
        }
        else
        {
            currentMax = nums[i];
        }
        if(max < currentMax)
        {
            max = currentMax;
        }
    }
    return max;
}

int main(void)
{
    std::vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
    int max = maxSubArray(v);
    std::cout << max << std::endl;
    return 0;
}

