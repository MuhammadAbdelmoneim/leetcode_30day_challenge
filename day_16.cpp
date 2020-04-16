#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <unordered_set>
#include <stack>


using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;




 bool checkValidString(string s) 
 {
     stack<int> openBrackets;
     stack<int> stars;
     int count = 0;
     for(auto i = 0; i < s.size(); i++)
     {
         if(s[i] == '(')
         {
             openBrackets.push(i);
         }
         else if(s[i] == '*')
         {
             stars.push(i);
         }
         else
         {
             if(!openBrackets.empty())
             {
                 openBrackets.pop();
             }
             else if(! stars.empty())
             {
                  stars.pop();
             }
             else
             {
                 return false;
             }
         }
     }
     while (!openBrackets.empty())
     {
         if(stars.empty()) { return false;}
         else
         {
             if(stars.top() > openBrackets.top())
             {
                 stars.pop();
                 openBrackets.pop();
             }
             else
             {
                 return false;
             }   
         }   
     }  
     return true;
 }


int main(void)
{
    string s{"((*"};
    if(checkValidString(s))
    {
         cout << "true" << endl;
    }
    else
    {
         cout << "false" << endl;
    }
    
   
    return 0;
}






