#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<int> numbers, int target, int sum = 0, int index = 0)
{
    if (index == numbers.size())
    {
        if (sum == target) answer++;
        return;
    }
    
    dfs(numbers, target, sum + numbers[index], index + 1);
    dfs(numbers, target, sum - numbers[index], index + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target);
    
    return answer;
}