#include "Pattern.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// O(n) where n is the number of chars in the big string

// Double hashmap isn't very space efficient but it makes this run quick as possible
bool wordPattern(string pattern, string str) {
	vector<string> words;
	string curword = ""; 
	for (auto c: str) {
		if (c == ' ') {
			words.push_back(curword);
			curword = "";
		}
		else {
			curword += c;
		}
	}

	words.push_back(curword);

	if (pattern.length() != words.size()) return false;

	map<char, string> nicemap;
	map<string, char> nicemap2;
	for (size_t i = 0; i < words.size(); i++) {
		if (nicemap[pattern[i]] == "" && nicemap2[words[i]] == '\0') {
			nicemap[pattern[i]] = words[i];
			nicemap2[words[i]] = pattern[i];
		}
		else if (nicemap[pattern[i]] != words[i] || nicemap2[words[i]] != pattern[i]) 
			return false;
	}
	return true;
}
