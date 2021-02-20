#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num) {
	if (num == 2) {
		return true;
	}
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int solution(vector<int> nums) {

	int answer = 0, size = nums.size(), temp = 0;

	for (int i = 0; i < size - 2; i++) {
		temp = nums[i];
		for (int j = i + 1; j < size - 1; j++) {
			temp += nums[j];
			for (int k = j + 1; k < size; k++) {
				temp += nums[k];
				if (isPrime(temp)) {
					answer++;
				}
				temp -= nums[k];
			}
			temp -= nums[j];
		}
	}
	return answer;
}


// time consumed: 10m?
// when search prime number, use this: for(int i=2; i*i<=num; i++). No needs to use <math.h> library and sqrt function, reducing execution time.