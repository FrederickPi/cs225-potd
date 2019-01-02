#include "Swiftcipher.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/* Swift Cipher: Frequency of words in a file corresponds to its location in the decrypted sentence */
string decipherer(string filename) {
	map<string, int> dict;

	string line;
    ifstream infile(filename);
    if (infile.is_open()) {
        while (getline(infile, line)) {  // O(n), n = lines
            dict[line]++;
        }
    }
    infile.close();

 	// O(n), n = number of different words
    vector<string> answer_arr(dict.size());
    for(auto pair: dict) 
       	answer_arr[pair.second - 1] = pair.first;

    // O(n), n = number of different words
    string answer = "";
    for (auto s: answer_arr)
    	answer += s + " ";

    answer.pop_back();

    return answer;
}