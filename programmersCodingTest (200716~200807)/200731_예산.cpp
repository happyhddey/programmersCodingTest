#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> budgets, int M) {
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int province_num = budgets.size(), answer = 0;
    
    // sort in increasing order
    for(int i=0; i<province_num; i++){
        pq.push(budgets[i]);
    }
    
    int sum = 0, left_budget = M, left_province = province_num, current_min = pq.top();
    // Find the point at which left budgets are insufficient
    while(current_min < left_budget/left_province){
        left_budget -= current_min;
        pq.pop();
        left_province--;
        // In case of all province gets full budgets
        if(left_province == 0){
            return current_min;
        }
        else{
            current_min = pq.top();
        }
    }
    
    // In case of all or some provinces gets insufficient budgets
    return left_budget/left_province;
}


//ahdi tlqkf
// time consumed: 52m