#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string binary_convert(int n)
{
    string binary = "";
    
    while (n > 0)
    {
        binary += to_string(n % 2);
        n /= 2;
    }
    
    reverse(binary.begin(), binary.end());
    
    return binary;
}

int char_counter(string s, char c)
{
    int count = 0;
    
    for (char a : s)
    {
        if (a == c) count++;
    }
    
    return count;
}

int solution(int n) {
    int answer = 0;
    int char_count = char_counter(binary_convert(n), '1');
    
    while (n < 1000000)
    {
        n++;
        int temp_count = char_counter(binary_convert(n), '1');
        if (char_count == temp_count)
        {
            answer = n;
            break;
        }
    }
    
    return answer;
}