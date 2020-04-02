#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

bool isHappy(unsigned int n){

     std::unordered_map<int, bool> seen_numbers;
  seen_numbers[n] = true;


  while (n != 1) {
    int sum_of_squares = 0;


    while (n > 0) {
      sum_of_squares += (n % 10) * (n % 10);
      n /= 10;
    }


    if (seen_numbers.find(sum_of_squares) != seen_numbers.end())
      return false;


    seen_numbers[sum_of_squares] = true;
    n = sum_of_squares;
  }


  return true;
}


int main(void)
{
    if(isHappy(19))
        std::cout << "hello"<< std::endl;
    else
        std::cout << "world"<< std::endl;

    return 0;
}


