#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    
    // level for height of rods, level_up for finding a laser
    int str_size = arrangement.size(), level = 0, answer = 0;
    bool level_up = true;
    
    for(int i=0; i<str_size; i++){
        
        if(arrangement[i] == '('){
            level++;
            level_up = true;
        }
        else{
            level--;
            // In case of LASER, because precedant arrangement was '('
            if(level_up){
                answer += level;
            }
            // In case of end of a rod
            else{
                answer += 1;
            }
            level_up = false;
        }
    }
    return answer;
}

// time consumed: 17m