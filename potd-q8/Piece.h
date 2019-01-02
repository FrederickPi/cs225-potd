#ifndef _PIECE_H
#define _PIECE_H

#include <string>
using namespace std;

class Piece {
	public:
		Piece();
		string getType();
	protected:
		string type_;
		string color_;
};

#endif
