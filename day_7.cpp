#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;
using std::unordered_map;

int countElements(vector<int>& arr) {
    unordered_map<int , int>m;
    vector<int>duplicates;
    int count = 0;
    for(auto i = 0; i < arr.size(); i++)
    {
        if(m.find(arr[i]) == m.end())
        {
            m.insert(std::make_pair(arr[i] , i));
        }
        else
        {
            duplicates.emplace_back(arr[i]);
        }
    }
    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(m.find((it->first + 1)) != m.end())
        {
            count++;
        }
    } 
    for(auto i = 0; i < duplicates.size(); i++)
    {
        if(m.find(duplicates[i] + 1) != m.end())
        {
            count++;
        }
    }
    return count;
}

int count(vector<int>&arr)
{
    int count = 0;
    int freq[1000];
    unordered_map<int , int>m;
    for(auto  i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }
    for(auto i = 0; i < 1000; i++)
    {
        if(freq[i] != 0)
        m.insert(std::make_pair(i , freq[arr[i]] ));
    }
    for(auto i = 0; i < arr.size(); i++)
    {
        if(m.find(arr[i] + 1) != m.end())
        {
            count += m.at(arr[i]);
        }
    }

    return count;
}

int main(void)
{
    vector<int> v{1,3,2,3,5,0};
    int x = countElements(v);
    cout << x << endl;


    return 0;
}