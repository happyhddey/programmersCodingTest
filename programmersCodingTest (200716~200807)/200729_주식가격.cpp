#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Price{
    int price;
    int index;
    Price(int p, int i):price(p), index(i){
    }
};

struct cmp{
    bool operator()(Price a, Price b){
        return a.price < b.price;
    }
};

vector<int> solution(vector<int> prices) {
    
    int prices_size = prices.size();
    int* sec = new int[prices_size];
    
    // priority queue for sorting in descending order
    priority_queue<Price, vector<Price>, cmp> find_max;
    find_max.push(Price(prices[0], 0));
    
    for(int i=1; i<prices_size; i++){
        int temp_price = prices[i];
        
        // if an element in priority queue has higher price than current price, count the seconds
        while(!find_max.empty()){
            Price max = find_max.top();
            if(max.price > temp_price){
                sec[max.index] = i - max.index;
                find_max.pop();
            }
            else{
                break;
            }
        }
        
        find_max.push(Price(prices[i], i));
    }
    
    // compute left calculations of prices which do not decreased
    while(!find_max.empty()){
        Price max = find_max.top();
        find_max.pop();
        sec[max.index] = prices_size - 1 - max.index;
    }
    
    // convert array into vector
    vector<int> answer;
    for(int i=0; i<prices_size; i++){
        answer.push_back(sec[i]);
    }
    delete[] sec;
    return answer;
}

// time consumed: 2h 2m