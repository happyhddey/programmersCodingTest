#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> citations) {
    
    priority_queue<int, vector<int>, less<int>> find_max;
    int size = citations.size(), citation = 0;
    
    // sort citations in increasing order
    for(int i=0; i<size; i++){
        find_max.push(citations[i]);
    }
    
    // compare nth highest citation and n
    for(int i=1; i<=size; i++){
        citation = find_max.top();
        if(citation == i){
            return citation;
        }
        // consider this case: [12,11,10,9,8,1] => 5
        else if(citation < i){
            return i-1;
        }
        find_max.pop();
    }
    
    // if citation of all paper exceeds the number of papers, return number of papers
    if(citation >= size){
        return size;
    }
}

// time consumed: 1h 30h
/*
1. Point of error: H-index doesn't need to be an element of citations
2. Useful testcases
[12,11,10,9,8,1] => 5
[6,6,6,6,6,1] => 5
[22,23] => 2
*/