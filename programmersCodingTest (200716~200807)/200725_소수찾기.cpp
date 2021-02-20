#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int num) {

	if (num == 1) {
		return false;
	}
	if (num == 2) {
		return true;
	}

	// test whether given number is prime or not
	int half = num / 2 + 1;
	bool isprime = true;
	for (int i = 2; i <= half; i++) {
		if (num % i == 0) {
			isprime = false;
			break;
		}
	}
	return isprime;
}

int countPrime(int num, int* numArray) {
	int cnt = 0;
    
	if (isPrime(num)) {
		cnt++;
	}
	for (int i = 0; i < 10; i++) {
		int temp = numArray[i];
		if (temp != 0) {
			numArray[i] = temp - 1;
			cnt += countPrime(num * 10 + i, numArray);
			numArray[i] = temp;
		}
	}
	return cnt;
}

int solution(string numbers) {

    // Count the number of each characters in numbers, 0 to 9
	int numbers_size = numbers.size();
	int numArray[10] = { 0, };
	for (int i = 0; i < numbers_size; i++) {
		int index = numbers[i] - '0';
		int temp = numArray[index];
		numArray[index] = temp + 1;
	}

    // Consider all possible combination. But, 0 cannot be on first.
	int answer = 0;
	for (int i = 1; i < 10; i++) {
		int temp = numArray[i];
		if (temp != 0) {
			numArray[i] = temp - 1;
			answer += countPrime(i, numArray);
			numArray[i] = temp;     // I made a mistake at here. numArray should be temp, not temp+1.
		}
	}

	return answer;
}

// Consumed Time: 1h 35m
// I made a mistake: didn't include number 2, 2 is also a prime number