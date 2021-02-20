#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {

	priority_queue<int, vector<int>, greater<int>> scoville_queue;

	int scoville_size = scoville.size();
	
	for (int i = 0; i < scoville_size; i++)
		scoville_queue.push(scoville[i]);

	int answer = 0;
	int least_one = scoville_queue.top();
	scoville_queue.pop();

	while (least_one < K) {
		if (scoville_queue.size() == 0) {
			return -1;
		}
		else {
			int less_one = scoville_queue.top();
			scoville_queue.pop();

			scoville_queue.push(least_one + less_one * 2);
			least_one = scoville_queue.top();
			scoville_queue.pop();

			answer++;
		}
	}
	return answer;
}
