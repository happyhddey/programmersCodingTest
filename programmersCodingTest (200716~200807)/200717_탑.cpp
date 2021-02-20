#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {

	vector<int> answer;
	int num_tower = heights.size();
	int height_to_tower[101] = { 0, };
	int height = 0;
	bool end = false;

	for (int i = 0; i < num_tower; i++) {
		end = false;
		height = heights[i];
		for (int j = height + 1; j <= 100; j++) {
			if (height_to_tower[j] != 0) {
				answer.push_back(height_to_tower[j]);
				end = true;
				break;
			}
		}
		if (!end) {
			answer.push_back(0);
		}
		height_to_tower[height] = i + 1;
		for (int j = 1; j < height; j++) {
			height_to_tower[j] = 0;
		}
	}


	return answer;
}
