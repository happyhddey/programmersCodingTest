#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int str_size = s.size(), level = 0;
    for(int i=0; i<str_size; i++){
        if(s[i] == '('){
            level++;
        }
        else{
            level--;
        }
        if(level < 0){
            return false;
        }
    }
    if(level == 0){
        return true;
    }
    else{
        return false;
    }
}

// Time Comsumed: 2m 6s
// I got an idea from the programming assignment of PL lecture. It used the 'level' variable for checking right program.