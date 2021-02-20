#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    // calculate required day for developing each task
    queue<int> required_days;
    int progress_size = progresses.size();
    
    for(int i=0; i<progress_size; i++){
        int progress = progresses[i], speed = speeds[i];
        if((100 - progress) % speed == 0){
            required_days.push((100 - progress)/speed);
        }
        else{
            required_days.push((100 - progress)/speed + 1);
        }
    }
    
    // find answer
    vector<int> answer;
    
    while(!required_days.empty()){
        int precedent_task = required_days.front(), cnt = 1;
        required_days.pop();
        
        while(!required_days.empty()){
            int following_task = required_days.front();
            if(precedent_task >= following_task){
                required_days.pop();
                cnt++;
            }
            else{
                break;
            }
        }
        answer.push_back(cnt);
    }    
    return answer;
}