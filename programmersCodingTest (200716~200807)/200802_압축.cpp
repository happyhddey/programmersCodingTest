#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    
    int size = msg.size(), iter = 0, newstr_size = 0;
    vector<string> newstr;
    vector<int> answer;
    
    while(iter < size){
        
        string substr = "";
        char start_char = msg[iter];
        iter++;
        
        // if start_char is a last element
        if(iter == size){
            answer.push_back(start_char - 'A' + 1);
            return answer;
        }
        substr.push_back(start_char);
        substr.push_back(msg[iter]);
        
        // if newstr is empty, add substr into newstr and add start_char to answer
        if(newstr.empty()){
            answer.push_back(start_char - 'A' + 1);
            newstr.push_back(substr);
            newstr_size++;
        }
        // if newstr is not empty
        else{
            bool here = false;
            int number = 0;
            for(int i=0; i<newstr_size; i++){
                if(substr == newstr[i]){
                    here = true;
                    iter++;
                    number = i;
                    if(iter < size){
                        substr.push_back(msg[iter]);
                    }
                    else{
                        answer.push_back(i + 27);
                        return answer;
                    }
                }
            }
            newstr.push_back(substr);
            newstr_size++;
            if(here){
                answer.push_back(number+27);
            }
            else{
                answer.push_back(start_char - 'A' + 1);
            }
        }
    }
    return answer;
}


// time consumed: 1h 21m