// Your code here
#include <string>
#include <iostream>

using namespace std;

int NUM_FORTUNES = 5;

string getFortune(const string &s) {
	int fortune_number = s.length() % NUM_FORTUNES; 
	if (fortune_number == 0) {
		return "Yes, I believe so.";
	}
	else if (fortune_number == 1) {
		return "No, I believe not.";
	}
	else if (fortune_number == 2) {
		return "I'm sorry, I can not answer that.";
	}
	else if (fortune_number == 3) {
		return "Yes, no, maybe so.";
	}
	return "Absolutely";
}