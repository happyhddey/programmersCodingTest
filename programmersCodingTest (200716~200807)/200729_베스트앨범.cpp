#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class information{
public:
    string genreName;
    int playTime;
    int first_time;
    int first_index;
    int second_time;
    int second_index;
    
    information(string g, int p, int first, int end){
        genreName = g;
        playTime = p;
        first_time = p;
        first_index = first;
        second_time = 0;
        second_index = end;
    }
    
    void update(int temp_time, int temp_index){
        
        playTime += temp_time;
        
        if(second_time <= temp_time){
                second_time = temp_time;
                second_index = temp_index;
        }
        if(first_time <= second_time){
            temp_time = first_time;
            temp_index = first_index;
            first_time = second_time;
            first_index = second_index;
            second_time = temp_time;
            second_index = temp_index;
        }
    }
};

// "bool operator()(type a, type b)"
struct cmp{
    bool operator()(information a, information b){
        return a.playTime < b.playTime;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    // genrename for storing element in genres, playtime for 
    vector<information> info;
    int all_size = genres.size(), info_size = 0;
    
    // count total play times
    for(int i=all_size-1; i>=0; i--){
        string gen = genres[i];
        bool isin = false;
        for(int j=0; j<info_size; j++){
            // update play time and first and second play songs
            if(info[j].genreName == gen){
                isin = true;
                info[j].update(plays[i], i);
                break;
            }
        }
        if(!isin){
            info.push_back(information(gen, plays[i], i, all_size));
            info_size++;
        }
    }
    
    // priority queue for sort genres in descending order
    priority_queue<information, vector<information>, cmp> pq;
    for(int i=0; i<info_size; i++){
        pq.push(info[i]);
    }
    
    vector<int> answer;
    while(!pq.empty()){
        information temp = pq.top();
        // push top 2 songs in queue
        answer.push_back(temp.first_index);
        if(temp.second_index != all_size){
            answer.push_back(temp.second_index);
        }
        pq.pop();
    }
    return answer;
}