#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        if (a[1] != b[1]) {
			return a[1] > b[1];
		}
		return a[0] > b[0];
    }
};

int solution(int m, int n, vector<vector<int>> puddles) {
    
    // sort puddles (compare n value first, then compare m)
    int num_puddle = puddles.size();
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq_puddles;
    for(int i=0; i<num_puddle; i++){
        pq_puddles.push(puddles[i]);
    }
    vector<int> puddle = pq_puddles.top();
    
    // make vector array for calculation
    vector<int> X_arr(m + 1);
    X_arr[1] = 1;
    
    for(int y=1; y<=n; y++){
        for(int x=1; x<=m; x++){
            // if there is a puddle, set a value as 0
            if((x == puddle[0]) && (y == puddle[1])){
                X_arr[x] = 0;
                pq_puddles.pop();
                puddle = pq_puddles.top();
            }
            // if there is not puddle, add y to current X_arr element
            else{
                int temp = X_arr[x-1] + X_arr[x];
                if(temp > 1000000007){
                    X_arr[x] = temp % 1000000007;
                }
                else{
                    X_arr[x] = temp;
                }
            }
        }        
    }
    return X_arr[m];
}

// time consumed: 1h 10m
// take care of writing bool operator of priority queue, especially in case of comparing elements with 2 or more standards