#include <string>
#include <vector>
#include <queue>

using namespace std;

struct job{
    int request_time;
    int operation_time;
    
    job(vector<int> job_i){
        request_time = job_i[0];
        operation_time = job_i[1];
    }
};

struct starting_time_cmp{
    bool operator()(job a, job b){
        return a.request_time > b.request_time;
    }
};

struct operation_time_cmp{
    bool operator()(job a, job b){
        return a.operation_time > b.operation_time;
    }
};

int solution(vector<vector<int>> jobs) {
    
    priority_queue<job, vector<job>, starting_time_cmp> left_jobs;
    priority_queue<job, vector<job>, operation_time_cmp> waiting;
    int jobs_size = jobs.size();
    for(int i=0; i<jobs_size; i++){
        left_jobs.push(jobs[i]);
    }
    
    int time = 0, answer = 0;
    while((!left_jobs.empty()) || (!waiting.empty())){
        
        // if there are some waiting jobs
        if(!waiting.empty()){
            
            // get job with shortest operation time from waiting
            time += waiting.top().operation_time;
            answer = answer + time - waiting.top().request_time;
            waiting.pop();
            
            // add left jobs into waiting, whose request time is less than or equal to estimated end time
            while((!left_jobs.empty()) && (left_jobs.top().request_time <= time)){
                waiting.push(left_jobs.top());
                left_jobs.pop();
            }
        }
        
        // if there is no waiting job
        else{
            
            // get a job from left jobs and set current time(equal to request time of this job)
            time = left_jobs.top().request_time;
            
            // add left jobs into waiting
            while((!left_jobs.empty()) && (left_jobs.top().request_time <= time)){
                waiting.push(left_jobs.top());
                left_jobs.pop();
            }
        }
    }
    return answer/jobs_size;
}


// time consumed: 50m
