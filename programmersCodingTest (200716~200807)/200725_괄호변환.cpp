#include <string>
#include <vector>

using namespace std;

string makeRightBracket(string str) {
	// 1. if input is empty string, return empty one
	if (str.empty()) {
		return str;
	}
	else {
		int str_size = str.size(), test = 0, sub = 0;
		bool everNegative = false;

		// 2. divide str into u and v
		for (int i = 0; i < str_size; i++) {
			if (str[i] == '(') {
				test++;
			}
			else if (str[i] == ')') {
				test--;
				if (test < 0) {
					everNegative = true;
				}
			}
			if (test == 0) {
				sub = i;
				break;
			}
		}
		string u = str.substr(0, sub + 1), v = str.substr(sub + 1);

		// 3. if u is right bracket
		if (!everNegative) {
			return u + makeRightBracket(v);
		}
		// 4. if u is not right bracket
		else {
			string new_v = makeRightBracket(v);
			int u_size = u.size();
			string new_u = "";
			for (int i = 1; i < u_size - 1; i++) {
				if (u[i] == '(') {
					new_u += ')';
				}
				else if (u[i] == ')') {
					new_u += '(';
				}
			}
			return '(' + new_v + ')' + new_u;
		}

	}
}

string solution(string p) {

	string answer = makeRightBracket(p);
	return answer;
}

// Consumed Time: 40m