#include <iostream>

using namespace std;


int main() {

	int C, R, seatNum;
	cin >> C >> R >> seatNum;

	if (seatNum > C * R) {
		cout << "0";
		return 0;
	}

	C--;
	R--;

	int N = 1, seatAround = (C + R) * 2;
	while (seatNum - seatAround > 0) {
		seatNum -= seatAround;
		N++;
		C -= 2;
		R -= 2;
		seatAround = (C + R) * 2;
	}

	int ansX = N, ansY = N, leftSeat = seatNum - 1;
	if (leftSeat - R <= 0) {
		ansY += leftSeat;
	}
	else {
		leftSeat -= R;
		ansY += R;
		if (leftSeat - C <= 0) {
			ansX += leftSeat;
		}
		else {
			leftSeat -= C;
			ansX += C;
			if (leftSeat - R <= 0) {
				ansY -= leftSeat;
			}
			else {
				leftSeat -= R;
				ansY -= R;
				ansX -= leftSeat;
			}
		}
	}

	cout << ansX << " " << ansY;

	return 0;
}