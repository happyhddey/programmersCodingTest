#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Container{
    string head;
    string number;
    string tail;
    
    string head_lower;
    int number_int;
    int index;
    
    Container(string filename, int i){
        number_int = 0;
        index = i;
        int len = filename.size(), start = 0;
        char find_head = filename[start];
        
        while(((find_head >= 'A') && (find_head <= 'z')) || (find_head == ' ') || (find_head == '.') || (find_head == '-')){
            head.push_back(find_head);
            if((find_head >= 'A') && (find_head <= 'Z')){
                head_lower.push_back(find_head + 32);
            }
            else{
                head_lower.push_back(find_head);
            }
            start++;
            find_head = filename[start];
        }
        
        while((find_head >= '0') && (find_head <= '9')){
            number.push_back(find_head);
            number_int = number_int*10 + int(find_head - '0');
            start++;
            if(start < len){
                find_head = filename[start];    
            }
            else{
                break;
            }
        }
        
        for(int j=start; j<len; j++){
            tail.push_back(filename[j]);
        }
        
        //cout << head << " " << number << " " << tail << "  ";
        //cout << head_lower << " " << number_int << " ";
    }
};

struct cmp{
    bool operator()(Container a, Container b){
        if(a.head_lower != b.head_lower){
            return a.head_lower > b.head_lower;
        }
        else{
            if(a.number_int != b.number_int){
                return a.number_int > b.number_int;
            }
            else{
                return a.index > b.index;
            }
        }
    }
};

vector<string> solution(vector<string> files) {
    
    priority_queue<Container, vector<Container>, cmp> pq;
    int size = files.size();
    
    for(int i=0; i<size; i++){
        Container c(files[i], i);
        pq.push(c);
    }
    
    vector<string> answer;
    for(int i=0; i<size; i++){
        Container temp = pq.top();
        string str = temp.head + temp.number + temp.tail;
        answer.push_back(str);
        pq.pop();
    }
    
    //Container con(".AbcDe-. 09-txt", 2);
    return answer;
}


// time consumed: 41m
// NOTE: I didn't know that c++ supports string comparison... It is also suprising that priority queue is so useful...