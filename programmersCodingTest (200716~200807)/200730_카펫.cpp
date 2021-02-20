#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    // Let length = x, height = y, then brown = 2(x-1) + 2(y-1) and yellow = (x-2)(y-2)
    // The total squares are sum of brown and yellow, total = brown + yellow
    
    int total = brown + yellow;
    int x = 0, y = 0, max_height = total / 2 + 1;
    vector<int> answer;
    
    for(int height = 3; height < max_height; height++){
        if(total % height == 0){
            y = height;
            x = total / y;
            if((brown == 2 * (x + y -2)) && (yellow == (x-2)*(y-2))){
                answer.push_back(x);
                answer.push_back(y);
                return answer;
            }
        }   
    }
}

// time consumed: 12m