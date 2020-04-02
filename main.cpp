#include <iostream>
#include <map>
#include <vector>



int singleNumber(std::vector<int>& nums) {
    /* Hash table */
    std::map<int , int> hashTable;
    

    for(auto i = 0; i < nums.size(); ++i){
        /* The element exits */
        if(hashTable.find(nums[i]) != hashTable.end())
        {
            /* Remove the element */
            hashTable.erase(nums[i]);
        }
        else
        {
            hashTable.insert(std::make_pair(nums[i] , i));
        }
    }
    std::map<int ,int>::iterator it = hashTable.begin();
    return it->first;
}

// 2 *(a + b + c) - (a + a + b + b + c) = c

int singleNumber_effecientSolution(std::vector<int>& nums){
    
    int a = 0;
    for(auto i = 0; i < nums.size(); ++i)
    {
        a = a ^ nums[i];
    }
    return a;
}

int main(void)
{
    std::vector<int> v{1,1,3,4,3};
    std::cout << singleNumber_effecientSolution(v) << std::endl;
    return 0;
}

