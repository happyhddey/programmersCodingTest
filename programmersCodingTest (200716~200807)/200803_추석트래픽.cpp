#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct RRtime{
    
    int request_time;
    int response_time;
    
    RRtime(string log_time){
        
        // response time first
        // hour(11, 12), minute(14,15), second(17,18,20,21,22)
        response_time = (int(log_time[11] - '0') * 10 + int(log_time[12] - '0')) * 3600000;
        response_time = response_time + (int(log_time[14] - '0') * 10 + int(log_time[15] - '0')) * 60000;
        response_time = response_time + int(log_time[17] - '0') * 10000 + int(log_time[18] - '0') * 1000 + int(log_time[20] - '0') * 100 + int(log_time[21] - '0') * 10 + int(log_time[22] - '0');
        //cout << response_time << " ";
        
        // request time
        // sec(24), ms(26,27,28)
        int mstime = int(log_time[24] - '0') * 1000, size = log_time.size();
        if(log_time[25] != 's'){
            if(size >= 28){
                mstime += int(log_time[26] - '0') * 100;
            }
            if(size >= 29){
                mstime += int(log_time[27] - '0') * 10;
            }
            if(size == 30){
                mstime += int(log_time[28] - '0');
            }
        }
        request_time = response_time - mstime + 1;
        //cout << request_time;
    }
    
};

struct request_cmp{
    bool operator()(RRtime a, RRtime b){
        if(a.request_time != b.request_time){
            return a.request_time > b.request_time;
        }
    }
};

struct response_cmp{
    bool operator()(RRtime a, RRtime b){
        if(a.response_time != b.response_time){
            return a.response_time > b.response_time;
        }
    }
};

int solution(vector<string> lines) {
    
    priority_queue<RRtime, vector<RRtime>, request_cmp> request;
    for(vector<string>::iterator iter=lines.begin(); iter<lines.end(); ++iter){
        request.push(RRtime(*iter));
    }
    
    priority_queue<RRtime, vector<RRtime>, response_cmp> response;
    int left = request.top().request_time, right, count = 0, max = 0;
    right = left + 1000;
    
    while(!((request.empty()) && (count == 0))){
        while((!response.empty()) && (response.top().response_time < left)){
            response.pop();
            count--;
        }
        while((!request.empty()) && (request.top().request_time < right)){
            response.push(request.top());
            request.pop();
            count++;
        }
        if(max < count){
            max = count;
        }
        left++;
        right++;
    }
    return max;
}


// time consumed: 2h 3m
// operator overloading is so useful