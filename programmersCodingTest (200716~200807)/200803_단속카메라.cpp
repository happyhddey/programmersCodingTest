#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        if(a[0] != b[0]){
            return a[0] > b[0];
        }
        else{
            if(a[1] != b[1]){
                return a[1] > b[1];
            }
        }
    }
};

int solution(vector<vector<int>> routes) {
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for(vector<vector<int>>::iterator iter=routes.begin(); iter<routes.end(); ++iter){
        pq.push(*iter);
    }
    
    /*
    Set lower bound and update lower bound.
    Especially when entrance point exceeds lower bound, count up answer.
    A camera is placed on previous lower bound point.
    */
    
    int answer = 0, lower_bound = 0;    
    while(!pq.empty()){    
        // set lower bound
        lower_bound = pq.top()[1];
        answer++;
        pq.pop();
        
        while(!pq.empty()){
            // update lower bound (entrance point is always smaller than current lower bound)
            if(pq.top()[1] <= lower_bound){
                lower_bound = pq.top()[1];
            }
            else{
                // In case that entrance point exceed lower bound, go to set lower bound
                if(lower_bound < pq.top()[0]){
                    break;
                }
            }
            pq.pop();
        }
    }
    return answer;
}


// time consumed: 40m