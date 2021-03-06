#include <iostream>

using namespace std;

class ScoreBoard {
private:
	int scoreA;
	int scoreB;

public:
	ScoreBoard() {
		scoreA = 0;
		scoreB = 0;
	}

	void updateScore(int a, int b) {
		if (a > b) {
			scoreA++;
		}
		else if (a < b) {
			scoreB++;
		}
	}

	char getWinner() {
		char winner = ' ';
		if (scoreA > scoreB) {
			winner = 'A';
		}
		else if (scoreA < scoreB) {
			winner = 'B';
		}
		else {
			winner = 'D';
		}
		return winner;
	}
};


int main() {

	ScoreBoard scoreBoard = ScoreBoard();
	int A[10], B[10];
	int a = 0, b = 0;

	for (int i = 0; i < 10; i++) {
		cin >> a;
		A[i] = a;
	}
	for (int i = 0; i < 10; i++) {
		cin >> b;
		B[i] = b;
	}

	for (int i = 0; i < 10; i++) {
		scoreBoard.updateScore(A[i], B[i]);
	}
	cout << scoreBoard.getWinner();

	return 0;
}