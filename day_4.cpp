#include <iostream>
#include <vector>
#include <algorithm>

/* Brute force solution */
void moveZeroes(std::vector<int>& nums) {
    std::vector<int> copy;
    int counter  = 0;
    for(auto i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == 0)
        {
            counter++;
        }
        else
        {
            copy.emplace_back(nums[i]);
        }
        
    }
    for(auto i = 0; i < counter; ++i)
    {
        copy.emplace_back(0);
    }
    nums = copy;

}

void moveZeroes_efficientSolution(std::vector<int>& nums)
{
    int count  = 0; 
    for(auto i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0)
        {
            nums[count++] = nums[i];
        }
    }

    while(count < nums.size())
    {
        nums[count++] = 0;
        
    }
    
}

int main(void)
{
    std::vector<int>v{0,1,0,3,12};
    moveZeroes_efficientSolution(v);
    for(auto &elem : v)
    {
        std::cout << elem << std::endl;
    }
    return 0;
}