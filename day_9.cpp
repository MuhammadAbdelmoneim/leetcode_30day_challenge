#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>




using std::cout;
using std::endl;
using std::vector;
using std::string;

 /* Will go with 2 pointer technique */
bool backspaceCompare(string S, string T) {
    
    auto A = 0;
    auto B = 0;

    while(S[B] != '\0')
    {
        B++;
        if(S[B] == '#') 
        {
            S.erase(A , 2);
            A = 0;
            B = 0;
        }
        else
        {
            A++;
        }
    }
    A = 0;
    B = 0;
    while(T[B] != '\0')
    {
        B++;
        if(T[B] == '#')
        {
            T.erase(A , 2);
            A = 0;
            B = 0;
        }
        else
        {
            A++;
        }
        
    }
    int e = 0;
    for(auto i = 0; i < S.size() - e; i++)
    {
        if(S[i] == '#')
        {
            S.erase(i , 1);
            e++;
            i--;
        }
    }
    e = 0;
    for(auto i = 0; i < T.size() - e; i++)
    {
        if(T[i] == '#')
        {
            T.erase(i , 1);
            e++;
            i--;
        }
    }
    if(S == T)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}




int  main(void)
{
    

    bool x = backspaceCompare("y#fo##f" , "y#f#o#f");
    cout << x << endl; 
    return 0;
}