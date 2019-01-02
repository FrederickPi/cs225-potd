
string beiju(string input) {
	string out = "";
	bool flag1 = false;
	string cur_beiju = "";
	for (char c: input) {
		if (flag1 && (c == ']' || c == '[')) {
			flag1 = false;
			out = cur_beiju + out;
			cur_beiju = "";
		}
		if (c == '[') flag1 = true;
		if (flag1 && c != '[' && c != ']') cur_beiju.push_back(c);
	}
	out = cur_beiju + out;

	bool flag2 = false;
    for (char c: input) {
    	if (c == '[') flag2 = true;
    	if (!flag2 && c != ']') out.push_back(c);
    	if (c == ']') flag2 = false;
    }
    return out;
}
