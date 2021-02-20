#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    
    string answer = "";
    int section = 1, deno = 3;

    while(true){
        if((n >= section) && (n < section + deno)){
            break;
        }
        else{
            section = section + deno;
            deno = deno * 3;
        }
    }
    
    while(true){
        
        if(deno == 3){
            switch(n){
                case 1:
                    answer.push_back('1');
                    break;
                case 2:
                    answer.push_back('2');
                    break;
                case 3:
                    answer.push_back('4');
                    break;
            }
            return answer;
        }
        else{
            deno = deno / 3;
            int temp = n - section;
            int quotient = temp/deno;
        
            switch(quotient){
                case 0:
                    answer.push_back('1');
                    break;
                case 1:
                    answer.push_back('2');
                    break;
                case 2:
                    answer.push_back('4');
                    break;
            }
            section = section - deno;
            n = section + temp % deno;
        }
    }
}
