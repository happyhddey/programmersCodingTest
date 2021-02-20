#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    
    int s_length = s.length(), sub_max = s_length / 2, min = 10000;
    
    if(s_length == 1){
        return 1;
    }
    
    for(int n=1; n<=sub_max; n++){  // n = sub string size, 1 ~ s_length / 2.
        int cnt = s_length, repetitive_cnt = 0, sub_num = s_length/n;
        
        for(int nth_sub = 0; nth_sub<sub_num-1; nth_sub++){
            int nth_index = nth_sub * n;
            bool equal = true;
            for(int j=0; j<n; j++){
                if(s.at(nth_index + j) != s.at(nth_index + n + j)){
                    equal = false;
                    break;
                }
            }
            if(equal){
                cnt = cnt - n;
                repetitive_cnt++;
            }
            else{
                if(repetitive_cnt != 0){
                    repetitive_cnt++;
                    int digit = 1;
                    while(repetitive_cnt >= 10){
                        repetitive_cnt = repetitive_cnt / 10;
                        digit++;
                    }
                    cnt = cnt + digit;
                    repetitive_cnt = 0;
                }
            }
        }
        
        if(repetitive_cnt != 0){
            repetitive_cnt++;
                int digit = 1;
                while(repetitive_cnt >= 10){
                    repetitive_cnt = repetitive_cnt / 10;
                    digit++;
                }
                cnt = cnt + digit;
        }
        
        if(min > cnt){
            min = cnt;
        }
    }
    
    return min;
}