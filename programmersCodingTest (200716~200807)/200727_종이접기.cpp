#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    
    // Imagine that you unfold the folded paper. It will show you the rule obviously.
    string u = "",  v = "";
    int size = 0;
    for(int i=0; i<n; i++){
        if(!u.empty()){
            // v equals to u except the middle element of u, the value is reversed
            string temp = u;
            if(temp[size/2] == '0'){
                temp[size/2] = '1';
            }
            else{
                temp[size/2] = '0';
            }
            v = temp;
        }
        // combine u and v with "0" in the middle, update size
        u = u + "0" + v;
        size = size * 2 + 1;
    }
    
    // convert string into vector<int>
    vector<int> answer;
    for(int j=0; j<size; j++){
        if(u[j] == '0'){
            answer.push_back(0);
        }
        else{
            answer.push_back(1);
        }
    }
    return answer;
}