#include <vector>
using namespace std;

void run2048(int puzzle[4][4], int dir) {
	
	vector<vector<bool>> combined(4, {false, false, false, false});
	// Left
	if (dir == 0) {
		for (unsigned x = 1; x < 4; x++) {
			for (unsigned y = 0; y < 4; y++) {
				if (puzzle[y][x] == 0) continue;
				unsigned curx = x;
				unsigned cury = y;
				while (curx > 0 && puzzle[cury][curx - 1] == 0) {
					puzzle[cury][curx - 1] = puzzle[cury][curx];
					puzzle[cury][curx] = 0;
					curx--;
				}
				if (curx != 0 && !combined[cury][curx - 1] && puzzle[cury][curx] == puzzle[cury][curx - 1]) {
					puzzle[cury][curx - 1] *= 2;
					puzzle[cury][curx] = 0;
					combined[cury][curx - 1] = true;
				}
				else if (curx != 3 && !combined[cury][curx] && puzzle[cury][curx] == puzzle[cury][curx + 1]) {
					puzzle[cury][curx] *= 2;
					puzzle[cury][curx + 1] = 0;
					combined[cury][curx] = true;
				}
			}
		}
	}
	// Up
	else if (dir == 1) {
		for (unsigned x = 0; x < 4; x++) {
			for (unsigned y = 1; y < 4; y++) {
				if (puzzle[y][x] == 0) continue;
				unsigned curx = x;
				unsigned cury = y;
				while (cury > 0 && puzzle[cury - 1][curx] == 0) {
					puzzle[cury - 1][curx] = puzzle[cury][curx];
					puzzle[cury][curx] = 0;
					cury--;
				}
				if (cury != 3 && !combined[cury][curx] && puzzle[cury][curx] == puzzle[cury + 1][curx]) {
					puzzle[cury][curx] *= 2;
					puzzle[cury + 1][curx] = 0;
					combined[cury][curx] = true;
				}
				else if (cury != 0 && !combined[cury - 1][curx] && puzzle[cury][curx] == puzzle[cury - 1][curx]) {
					puzzle[cury - 1][curx] *= 2;
					puzzle[cury][curx] = 0;
					combined[cury - 1][curx] = true;
				}
			}
		}
	}
	// Right
	else if (dir == 2) {
		for (int x = 2; x >= 0; x--) {
			for (unsigned y = 0; y < 4; y++) {
				if (puzzle[y][x] == 0) continue;
				unsigned curx = x;
				unsigned cury = y;
				while (curx < 3 && puzzle[cury][curx + 1] == 0) {
					puzzle[cury][curx + 1] = puzzle[cury][curx];
					puzzle[cury][curx] = 0;
					curx++;
				}
				if (curx != 3 && !combined[cury][curx + 1] && puzzle[cury][curx] == puzzle[cury][curx + 1]) {
					puzzle[cury][curx] = 0;
					puzzle[cury][curx + 1] *= 2;
					combined[cury][curx + 1] = true;
				}
				else if (curx != 0 && !combined[cury][curx] && puzzle[cury][curx] == puzzle[cury][curx - 1]) {
					puzzle[cury][curx - 1] = 0;
					puzzle[cury][curx] *= 2;
					combined[cury][curx] = true;
				}
			}
		}
	}
	// Down
	else if (dir == 3) {
		for (unsigned x = 0; x < 4; x++) {
			for (int y = 2; y >= 0; y--) {
				if (puzzle[y][x] == 0) continue;
				unsigned curx = x;
				unsigned cury = y;
				while (cury < 3 && puzzle[cury + 1][curx] == 0) {
					puzzle[cury + 1][curx] = puzzle[cury][curx];
					puzzle[cury][curx] = 0;
					cury++;
				}
				if (cury != 3 && !combined[cury + 1][curx] && puzzle[cury][curx] == puzzle[cury + 1][curx]) {
					puzzle[cury][curx] = 0;
					puzzle[cury + 1][curx] *= 2;
					combined[cury][curx] = true;
				}
				else if (cury != 0 && !combined[cury][curx] && puzzle[cury][curx] == puzzle[cury - 1][curx]) {
					puzzle[cury - 1][curx] = 0;
					puzzle[cury][curx] *= 2;
					combined[cury][curx] = true;
				}
			}
		}
	}
}
