#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {

    int needs = t*m, str_size = 0, count = 1;
    string list = "0123456789ABCDEF", ans = "0";

    while(str_size <= needs){
        string temp = "";
        int start = count;
        while(start != 0){
            temp += list[start%n];
            start = start/n;
        }
        int temp_size = temp.size();
        for(int i=temp_size-1; i>=0; i--){
            ans += temp[i];
        }
        count++;
        str_size += temp_size;
    }

    string answer = "";
    for(int i=p-1; i<needs; i = i+m){
        answer += ans[i];
    }

    return answer;
}


// time consumed: 15m
