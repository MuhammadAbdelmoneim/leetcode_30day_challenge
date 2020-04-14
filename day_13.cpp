#include <iostream>
#include <vector>
#include<map>
#include <unordered_map>



using std::cout;
using std::endl;
using std::vector;

//[0 1 0 1 0 1 0 0] 
int findMaxLength(vector<int>& nums) {
    int A = 0;
    int B = 1;
    int count = 1;
    int max = 0;
    if(nums.size() == 0)
    {
        return 0;
    }
    if(nums.size() == 1)
    {
     return 1;   
    }
    if(nums.size() == 2)
    {
        return ((nums[0] == nums[1]) ? 1 : 2);
    }
      
    while(nums[A] == nums[B] && B < nums.size())
    {
        ++A;
        ++B;
    }
    while(B < nums.size())
    {
        while((B < nums.size()) && nums[B] != nums[B - 1])
        {
            ++B;
            ++count;
        }
        if(max < count)
        {
            max = count;
            count = 0;
        }
    }
    return (max % 2 == 1) ? max - 1 : max;
}
int main(void)
{

    vector<int> v{1,0,1,0};
    cout << findMaxLength(v) << endl;

    return 0;
}

