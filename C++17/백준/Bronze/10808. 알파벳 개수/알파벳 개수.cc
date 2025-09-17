#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    string S;
    cin >> S;
    
    int count[26] = {0};
    
    // TODO: 문자열 S를 순회하면서 각 알파벳의 개수를 count에 기록
    // a-z까지 저장한 딕셔너리 선언
    // 반복문 돌면서 딕셔너리의 키에 해당하면 밸류 증가
    // 딕셔너리 밸류 출력

    map<char, int> alphabet;
    for (int i = 0; i < 26; i++)
    {
        alphabet.insert(pair<char, int>('a' + i, 0));
    }
    
    for (char c : S)
    {
        alphabet[c] += 1;
    }

    for (char c = 'a'; c <= 'z'; c++)
    {
        cout << alphabet[c];
        if (c != 'z') cout << " ";
    }
    
    return 0;
}