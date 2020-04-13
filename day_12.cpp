#include <iostream>
#include <vector>
#include <algorithm>
#include <string>




using std::cout;
using std::endl;
using std::vector;

/* Correct from the first time */
int lastStoneWeight(vector<int>& stones) {
    while(stones.size() != 0)
    {
        std::sort(std::begin(stones) , std::end(stones));
        if(stones.size() != 0)
        {
            if(stones.size() == 1)
            {
                return stones[0];
            }
            if(stones[stones.size()-1] > stones[stones.size()-2] )
            {
                stones[stones.size()-1] = stones[stones.size()-1] - stones[stones.size()-2];
                std::swap(stones[stones.size()-1] , stones[stones.size()-2]);
                stones.erase(stones.begin() + (stones.size()- 1));
            }
            else
            {
                stones.erase(stones.begin() + (stones.size()- 1));
                stones.erase(stones.begin() + (stones.size()- 1));
            }
            
            
        }
        
    }
    return 0;
}



int main(void)
{
    /* Test case 1 : passed */ 
    vector<int> v{2,7,4,1,8,1};
    cout << lastStoneWeight(v) << endl;
    return 0;
}

















