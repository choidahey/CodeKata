#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


string binary_conversion(int n)
{
    string binary = "";
    
    while (n != 0)
    {
        binary += to_string(n % 2);
        n /= 2;
        
        cout << binary << endl;
    }
    
    reverse(binary.begin(), binary.end());

    return binary;
}


int counter(string s, char c)
{
    int counter = 0;
    
    if (find(s.begin(), s.end(), c) != s.end())
    {
        for (char a : s)
        {
            if (a == c)
                counter++;
        }
    }
    
    return counter;
}

vector<int> solution(string s) {
    vector<int> answer;
    int zero_count = 0;
    int one_count = 0;
    int transfer_count = 0;
    
    while (s != "1")
    {
        // 1. 0 갯수 카운트
        zero_count += counter(s, '0');
        // 2. 0 제거
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        // 3. 현재 s 의 길이 저장
        one_count = s.size();
        // 4. 저장된 현재 s 길이로 이진변환 수행
        s = binary_conversion(one_count);
        // 5. 0 없으면 리턴
        
        transfer_count++;
    }
    
    answer.push_back(transfer_count);
    answer.push_back(zero_count);
    
    return answer;
}