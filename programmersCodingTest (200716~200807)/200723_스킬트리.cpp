#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    
    int answer = 0, tree_size = skill_trees.size(), skill_length = skill.length();
    
    for(int i=0; i<tree_size; i++){
        string user = skill_trees[i];
        int user_length = user.length();
        string skill_sequence = "";
        
        // append skill_sequence when user skill includes given skill.
        for(int j=0; j<user_length; j++){
            char temp = user[j];
            for(int k=0; k<skill_length; k++){
                if(temp == skill[k]){
                    skill_sequence.push_back(temp);
                    break;
                }
            }
        }
        
        // compare user tree and skill. If there is a difference, user tree is not right tree.
        int skill_sequence_size = skill_sequence.size();
        bool right_tree = true;
        for(int j=0; j<skill_sequence_size; j++){
            if(skill_sequence[j] != skill[j]){
                right_tree = false;
                break;
            }
        }
        
        if(right_tree){
            answer++;
        }
    }

    return answer;
}
