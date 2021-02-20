#include <string>
#include <vector>
#include <queue>

using namespace std;

class doublePriorityQueue{
private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, less<int>> deleted_min_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, greater<int>> deleted_max_heap;
    int heap_size;
    
public:
    
    doublePriorityQueue(){
        heap_size = 0;
    }
    
    void oper(string str){
        
        // Insert
        if(str[0] == 'I'){
            int str_size = str.size(), temp = 0;
            if(str[2] == '-'){
                for(int i=3; i<str_size; i++){
                    temp = temp * 10 + int(str[i] - '0');
                }
                temp *= (-1);
            }
            else{
                for(int i=2; i<str_size; i++){
                    temp = temp * 10 + int(str[i] - '0');
                }
            }
            max_heap.push(temp);
            min_heap.push(temp);
            heap_size++;
        }
        // Delete
        else{
            // delete min
            if(str[2] == '-'){
                while((!deleted_max_heap.empty()) && (min_heap.top() == deleted_max_heap.top())){
                    min_heap.pop();
                    deleted_max_heap.pop();
                }
                if(!min_heap.empty()){
                    deleted_min_heap.push(min_heap.top());
                    min_heap.pop();
                    heap_size--;
                }
            }
            // delete max
            else{
                while((!deleted_min_heap.empty()) && (max_heap.top() == deleted_min_heap.top())){
                    max_heap.pop();
                    deleted_min_heap.pop();
                }
                if(!max_heap.empty()){
                    deleted_max_heap.push(max_heap.top());
                    max_heap.pop();
                    heap_size--;
                }
            }
        }
    }
    
    int get_max(){
        if(heap_size == 0){
            return 0;
        }
        else{
            while((!deleted_max_heap.empty()) && (min_heap.top() == deleted_max_heap.top())){
                min_heap.pop();
                deleted_max_heap.pop();
            }
            return max_heap.top();
        }
    }
    
    int get_min(){
        if(heap_size == 0){
            return 0;
        }
        else{
            while((!deleted_min_heap.empty()) && (max_heap.top() == deleted_min_heap.top())){
                max_heap.pop();
                deleted_min_heap.pop();
            }
            return min_heap.top();
        }
    }
};

vector<int> solution(vector<string> operations) {
    
    doublePriorityQueue pq;
    int operation_size = operations.size();
    for(int i=0; i<operation_size; i++){
        pq.oper(operations[i]);
    }
    
    vector<int> answer;
    answer.push_back(pq.get_max());
    answer.push_back(pq.get_min());
    return answer;
}



// time consumed: 50m
