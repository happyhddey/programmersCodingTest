#include <iostream>

using namespace std;

int main() {

	int lenX, lenY, initX, initY, time, marginX, marginY;
	cin >> lenX >> lenY >> initX >> initY >> time;
	marginX = lenX - initX;
	marginY = lenY - initY;

	int numCrossX = (time - marginX) / lenX, leftX = (time - marginX) % lenX;
	int numCrossY = (time - marginY) / lenY, leftY = (time - marginY) % lenY;

	int ansX, ansY;
	if (numCrossX % 2 == 0) {
		ansX = lenX - leftX;
	}
	else {
		ansX = leftX;
	}
	if (numCrossY % 2 == 0) {
		ansY = lenY - leftY;
	}
	else {
		ansY = leftY;
	}

	cout << ansX << " " << ansY;

	return 0;
}
