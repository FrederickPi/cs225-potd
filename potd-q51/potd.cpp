#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;


vector<string> topThree(string filename) {
    map<string, int> dict; 
    vector<string> ret;

    string line;
    ifstream infile (filename);
    if (infile.is_open()) {
        while (getline(infile, line)) {  // O(n), n = lines
            dict[line]++;
        }
    }
    infile.close();

    // O(n), n = items in dictionary
    int max = 0;
    string max_str = "";
    for (auto pair: dict) 
        if (pair.second > max) {
            max_str = pair.first;
            max = pair.second;
        }
    if (max_str != "") ret.push_back(max_str);
    else return ret;
    
    max = 0;
    max_str = "";
    for (auto pair: dict) 
        if (pair.second > max && pair.first != ret.back()) {
            max_str = pair.first;
            max = pair.second;
        }
    if (max_str != "") ret.push_back(max_str);
    else return ret;

    max = 0;
    max_str = "";
    for (auto pair: dict) 
        if (pair.second > max && pair.first != ret.back() && pair.first != ret.front()) {
            max_str = pair.first;
            max = pair.second;
        }
    if (max_str != "") ret.push_back(max_str);

    return ret;
}

