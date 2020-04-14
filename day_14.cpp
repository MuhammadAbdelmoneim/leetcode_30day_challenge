#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


string stringShift(string s, vector<vector<int>>& shift) {
    int left = 0;
    int right = 0;
    int num_of_shift = 0;
    string copy = s;
    for(auto i = 0 ; i < shift.size(); ++i)
    {
        if(shift[i][0] == 0)
        {
            left += shift[i][1];
        }
        else
        {
            right += shift[i][1];
        }
    }
    num_of_shift = left - right;
    
    if(num_of_shift == 0)
        return s;
    if(num_of_shift > 0)
    {
        /* it means left shift */
        for(auto i = 0; i < num_of_shift; i++)
        {
            for(auto j = 0; j < s.size() - 1; j++)
            {
                s[j] = s[j + 1];
            }
            s[s.size() - 1] = copy[0];
            copy = s;
        }
    }
    else
    {
        /* it means rigth shift */
        num_of_shift = right - left;
        for(auto i = 0;  i < num_of_shift; i++)
        {
            for(auto j = s.size() - 1; j > 0; j--)
            {
                s[j] = s[j - 1];
            }
            s[0] = copy[s.size() - 1];
            copy = s;
        }
    }
    return s;
}

int main(void)
{
    string s{"abc"};
    vector<vector<int>>v{{0,1},{1,2}};

    cout << stringShift(s,v) << endl;
    return 0;
}