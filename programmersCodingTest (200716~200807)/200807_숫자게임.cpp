#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    
    // sort A and B in descending order
    int size = A.size(), answer = 0;
    priority_queue<int, vector<int>, less<int>> teamA;
    priority_queue<int, vector<int>, less<int>> teamB;
    for(int i=0; i<size; i++){
        teamA.push(A[i]);
        teamB.push(B[i]);
    }
    
    // pop element of team A until max of team B is larger than that of team A
    // The number of element of team B is always larger than that of A because an element is not popped only from B
    while(!teamA.empty()){
        if(teamB.top() > teamA.top()){
            teamA.pop();
            teamB.pop();
            answer++;
        }
        else{
            teamA.pop();
        }
    }
    
    return answer;
}


// time consumed: 15m