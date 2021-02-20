#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

	stack<int> truck_on_bridge;
	int current_weight = 0, left_distance = 0, answer = 0;
	int truck_number = truck_weights.size();
	int* distance_btw_trucks = new int[truck_number];
	for (int i = 0; i < truck_number; i++) {
		distance_btw_trucks[i] = 1;
    }

	for (int i = 0; i < truck_number; i++) {
		current_weight = truck_weights[i];
		left_distance = 0;
		for (int j = 1; j < bridge_length; j++) {
			if (i + j >= truck_number) {
				break;
			}
			else {
				current_weight += truck_weights[i + j];
				if (current_weight <= weight) {
					left_distance += distance_btw_trucks[i + j];
				}
				else {
					distance_btw_trucks[i + j] = bridge_length - left_distance;
					break;
				}
			}
		}
	}

	//distance_btw_trucks[truck_number - 1] = 0;
	for (int i = 0; i < truck_number; i++) {
		answer += distance_btw_trucks[i];
	}
	answer = answer + bridge_length;

	delete[] distance_btw_trucks;

	return answer;
}
