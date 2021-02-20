#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    // Fibonacci starting from 1, f(1)=1 and f(2)=2
    // The problem "Represents number n only with 1 or 2" is same with this problem
    
    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    else if(n > 2){
        int n_1 = 2, n_2 = 1, ans;
        for(int i=3; i<=n; i++){
            ans = n_1 + n_2;
            if(ans > 1000000007){
                ans = ans % 1000000007;
            }
            n_2 = n_1;
            n_1 = ans;
        }
        return ans;
    }
}


// time consumed: 40m