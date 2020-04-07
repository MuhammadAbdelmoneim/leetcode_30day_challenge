#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <memory>
#include <unordered_map>
using std::cout;
using std::endl;
using std::vector;
using std::string;

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]




vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<string , vector<string>>hashTable;
    std::vector<vector<string>> groupAnagrams;
    for(auto i  = 0; i < strs.size(); ++i)
    {
        string copy = strs[i];
        std::sort(strs[i].begin() , strs[i].end());
        if(hashTable.find(strs[i]) == hashTable.end())
        {
            vector<string> tmp;
            tmp.emplace_back(copy);
            hashTable.insert(std::make_pair(strs[i] , tmp));
        }
        else
        {
            hashTable.at(strs[i]).emplace_back(copy);
        }
    }
    for(auto it = hashTable.begin(); it != hashTable.end(); it++)
    {
        groupAnagrams.emplace_back(it->second);
    }
    return groupAnagrams;
}

int main(void)
{
    vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(v);
    for(auto i = 0; i < res.size(); i++)
    {
        for(auto j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << "  ";
        }
        cout << "\n";
    }
    return 0;
}









