#include <vector>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool isHam(char a) {
	if (a == 'H') {
		return true;
	}
	else {
		return false;
	}
}

bool isInBoundary(int K, int distance) {
	if (abs(distance) <= K) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	
	vector<int> hamList;
	vector<int> perList;

	int N = 0, K = 0;
	string str = "";
	cin >> N >> K >> str;

	for (int i = 0; i < N; i++) {
		char ch = str[i];
		if (isHam(ch)) {
			hamList.push_back(i);
		}
		else {
			perList.push_back(i);
		}
	}

	int hamNum = hamList.size(), hamIndex = 0, perNum = perList.size(), perIndex = 0, answer = 0;
	while ((hamIndex < hamNum) && (perIndex < perNum)) {
		if (isInBoundary(K, hamList[hamIndex] - perList[perIndex])) {
			answer++;
			hamIndex++;
			perIndex++;
		}
		else {
			if (hamList[hamIndex] < perList[perIndex]) {
				hamIndex++;
			}
			else {
				perIndex++;
			}
		}
	}

	cout << answer;

	return 0;
}