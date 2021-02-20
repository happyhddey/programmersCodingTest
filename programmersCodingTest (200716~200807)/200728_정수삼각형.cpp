#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    
    int height = triangle.size();
    for(int k=1; k<height; k++){
        
        // calculate first and last element
        triangle[k][0] = triangle[k][0] + triangle[k-1][0];
        triangle[k][k] = triangle[k][k] + triangle[k-1][k-1];
        
        // calaulte middle elements
        for(int i=1; i<k; i++){
            if(triangle[k-1][i-1] < triangle[k-1][i]){
                triangle[k][i] = triangle[k][i] + triangle[k-1][i];
            }
            else{
                triangle[k][i] = triangle[k][i] + triangle[k-1][i-1];
            }
        }   
    }
    
    // find highest value at last floor
    vector<int> highest_floor = triangle[height-1];
    int max = highest_floor[0];
    for(int i=1; i<height; i++){
        cout << highest_floor[i];
        if(max < highest_floor[i]){
            max = highest_floor[i];
        }
    }
    return max;
}


// time consumed: 25m
