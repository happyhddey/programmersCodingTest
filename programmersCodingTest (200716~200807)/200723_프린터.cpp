#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    
    // declare variables: find_max queue is for finding maximal priority fast(decrease search time)
    priority_queue<int, vector<int>, less<int>> find_max;
    int pri_size = priorities.size(), answer = 0;
    
    for(int i=0; i<pri_size; i++){
        find_max.push(priorities[i]);
    }
    
    // set starting condition: find max and set head(head is the index of document with highest priority, and is printed in that instant)
    int max = find_max.top(), head, my_doc = priorities[location];

    for(int i=0; i<pri_size; i++){
        if(priorities[i] == max){
            head = i % pri_size;  // set head with index of max element
            find_max.pop();
            answer++;
            break;
        }
    }
    
    // update head and find_max queue until head equals to location. In that moment, my document is printed.
    while(head != location){
        max = find_max.top();
        for(int j=1; j<pri_size; j++){
            if(priorities[(head+j) % pri_size] == max){
                head = (head+j) % pri_size;
                find_max.pop();
                answer++;
                break;
            }
        }
    }
    return answer;
}
