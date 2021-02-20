#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    vector<string> type;
    vector<int> count;
    int clothes_num = clothes.size();
    
    for(int i=0; i<clothes_num; i++){
        vector<string> cloth = clothes[i];
        bool isintype = false;
        for(int j=0; j<type.size(); j++){
            if(type[j] == cloth[1]){
                int temp = count[j];
                count[j] = temp+1;
                isintype = true;
                break;
            }
        }
        if(!isintype){
            type.push_back(cloth[1]);
            count.push_back(1);
        }
    }
    
    int ans = count[0] + 1, count_size = count.size();
    for(int i=1; i<count_size; i++){
        ans *= (count[i]+1);
    }
    return ans-1;
}

// time consumed: 50m
// it useds formula (A+1)(B+1)(C+1) - 1.. I had a difficulty for coming up this