#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const pair<int, double>& a, const pair<int, double>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
} 

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> stage_fail;
    
    for (int i = 1; i <= N; i++)
    {
        int stage_count = 0;
        int fail_count = 0;
        
        for (int j = 0; j < stages.size(); j++)
        {
            if (stages[j] >= i)
                stage_count++;
            
            if (stages[j] == i)
                fail_count++;
        }
        
        double fail_rate = 0.0;
        if (stage_count > 0)
            fail_rate = (double)fail_count / stage_count;
        
        stage_fail.push_back(pair<int, double>(i, fail_rate));
        
        
    }
    
    sort(stage_fail.begin(), stage_fail.end(), cmp);
        
    for (pair<int, double> p : stage_fail)
    {
        answer.push_back(p.first);
    }
    
    return answer;
}