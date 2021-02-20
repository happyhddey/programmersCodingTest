#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    
    int size = s.size(), answer = 0;
    
    // odd length
    for(int i=0; i<size; i++){
        
        int left = i, right = size-i-1, min, max=0;
        
        if(left < right){
            min = left;
        }
        else{
            min = right;
        }
        
        for(int j=1; j<=min; j++){
            // I made a mistake at here.. aabac might be counterexample
            if(s[i-j] != s[i+j]){
                break;
            }
            max++;
        }
        max = max * 2 + 1;
        if(max > answer){
            answer = max;
        }
    }
    
    // even length
    for(int i=0; i<size-1; i++){
        
        int left = i, right = size-i-2, min, max=0;
        
        if(left < right){
            min = left;
        }
        else{
            min = right;
        }
        
        if(s[i] == s[i+1]){
            max++;
            for(int j=1; j<=min; j++){
                if(s[i-j] != s[i+1+j]){
                    break;
                }
                max++;
            }
            max *= 2;
            if(max > answer){
                answer = max;
            }
        }
    }
    return answer;
}


// time consumed: 30m