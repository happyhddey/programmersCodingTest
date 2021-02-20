#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    
    int size = name.size(), upDown = 0, leftRight = 0;
    
    // Count number of controlling stick with up or downside
    for(int i=0; i<size; i++){
        if(name[i] <= 'M'){
            upDown += (name[i] - 'A');
        }
        else{
            upDown += ('A' + 26 - name[i]);
        }
    }
    
    
    // Count number of controlling stick with left or rightside
    name[0] = 'A';
    vector<int> notAindex;
    for(int i=0; i<size; i++){
        if(name[i] != 'A'){
            notAindex.push_back(i);
        }
    }
    
    // only forward or reverse direction
    int index_size = notAindex.size();
    if(notAindex[index_size-1] < size - notAindex[0]){
        leftRight = notAindex[index_size-1];
    }
    else{
        leftRight = size - notAindex[0];
    }
    
    // forward direction -> reverse direction
    for(int i=0; i<index_size-1; i++){
        int temp = notAindex[i] * 2 + (size - notAindex[i+1]);
        if(temp < leftRight){
            leftRight = temp;
        }
    }
    // reverse direction -> forward direction
    for(int i=0; i<index_size - 1; i++){
        int temp = (size - notAindex[i+1]) * 2 + notAindex[i];
        if(temp < leftRight){
            leftRight = temp;
        }
    }
    
    return upDown + leftRight;
}



/*
    
    // Wrong Code for leftRight part (Counterexample: "AZAAAZAAAAAAAZA", 12)
    
    name[0] = 'A';
    int difference = 1, current_index = 0;
    while(difference != size/2 + 1){
        
        int right_index = (current_index + difference) % size;
        int left_index = (current_index + size - difference) % size;
        //cout << current_index << "/";
        
        if((name[right_index] != 'A')){
            name[right_index] = 'A';
            current_index = right_index;
            leftRight += difference;
            //cout << difference << " ";
            difference = 1;
        }
        else if(name[left_index] != 'A'){
            name[left_index] = 'A';
            current_index = left_index;
            leftRight += difference;
            //cout << difference << " ";
            difference = 1;
        }
        else{
            difference++;
        }
    }
*/


// time consumed: 2h 11m