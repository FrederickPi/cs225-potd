#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> st;
    for (unsigned c = 0; c < input.size(); c++) {
    	char letter = input[c];
    	if (letter == '[' || letter == '(' || letter == '{') {
    		st.push(letter);
    		continue;
    	}
    	if (!st.empty()) { 
    		if (st.top() == '[' && letter == ']') st.pop();
    		else if (st.top() == '(' && letter == ')') st.pop();
    		else if (st.top() == '{' && letter == '}') st.pop();
    		else if (letter == ']' || letter == ')' || letter == '}') st.push(letter);
    	}
    	else if (letter == ']' || letter == ')' || letter == '}') st.push(letter);
    }
    cout << st.size() << endl;
    return st.empty();
}