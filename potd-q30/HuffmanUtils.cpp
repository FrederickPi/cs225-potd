#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

void getPaths(vector<vector<char>> &paths, HuffmanNode * current) {
    if (current->left_ == NULL && current->right_ == NULL) {
        paths.back().push_back(current->char_);
        vector<char> next = paths.back();
        next.pop_back();
        paths.push_back(next);
    }
    else {
        if (current->left_ != NULL) {
        	paths.back().push_back('0');
        	getPaths(paths, current->left_);
        	paths.back().pop_back();
       	}
        if (current->right_ != NULL) {
        	paths.back().push_back('1');
        	getPaths(paths, current->right_);
        	paths.back().pop_back();
        }
    }
}

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */

string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    char cur_char;
    string answer = "";
    HuffmanNode * curNode = huffmanTree;
    for (unsigned i = 0; i < binaryString.length(); i++) {
    	cur_char = binaryString[i];
    	if (cur_char == '0') {curNode = curNode->left_;}
    	else if (cur_char == '1') {curNode = curNode->right_;}
    	if (curNode->left_ == NULL && curNode->right_ == NULL) {
    		answer = answer + curNode->char_;
    		curNode = huffmanTree;
    	}
    }
    return answer;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string answer = "";
    char curChar;
    vector<vector<char>> paths;
    paths.resize(1);
    getPaths(paths, huffmanTree);
    paths.pop_back();
    for (unsigned i = 0; i < charString.length(); i++) {
    	curChar = charString[i];
    	for (unsigned j = 0; j < paths.size(); j++) {
    		if (paths[j].back() == curChar) {
    			for (unsigned k = 0; k < paths[j].size() - 1; k++) {
    				answer = answer + paths[j][k];
    			}
    			break;
    		}
    	}
    }
    return answer;
}
