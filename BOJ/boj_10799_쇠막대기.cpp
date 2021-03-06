#include <iostream>
#include <string>

using namespace std;

int main() {

	int numRod = 0, answer = 0;
	string question = "";

	cin >> question;
	
	char prevq = '(';
	int questionLen = question.length();
	for (int i = 0; i < questionLen; i++) {
		char q = question[i];
		if (q == '(') {
			numRod++;
		}
		else if((prevq == '(') && (q == ')')) {
			numRod--;
			answer += numRod;
		}
		else {
			answer++;
			numRod--;
		}
		prevq = q;
	}
	
	cout << answer;

	return 0;
}