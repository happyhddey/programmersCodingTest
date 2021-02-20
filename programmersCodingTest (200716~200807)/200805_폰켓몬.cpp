#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    bool pocket[200000] = {false, };
    int num_size = nums.size(), type_num = 0, max_size = num_size/2;
    
    for(int i=0; i<num_size; i++){
        if(!pocket[nums[i] - 1]){
            pocket[nums[i] - 1] = true;
            type_num++;
        }
        if(type_num >= max_size){
            return max_size;
        }
    }
    return type_num;
}



// time consumed: 27m
