#include "stats.h"
#include "globals.h"
#include <iostream>

Stats::Stats() {
	s_world = new char*[MAX_ROWS];
	i_world = new int*[MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		s_world[i] = new char[MAX_COLS];
		i_world[i] = new int[MAX_COLS];
	}

	//Initialize
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			s_world[i][j] = DEAD;
			i_world[i][j] = 0;
		}
	}
}

Stats::~Stats() {
	for (int i = 0; i < MAX_ROWS; i++) {
		delete[] s_world[i];
		delete[] i_world[i];
	}
	delete[] s_world;
	delete[] i_world;
}

void Stats::display() const {
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			if (i_world[i][j] != 0) { // for the cell that has changed,
				std::cout << i_world[i][j]; //print int value
			}
			else {
				std::cout << s_world[i][j]; //print DEAD cell
			}
		}
		std::cout << '\n';
	}
	std::cout << "\nPlease enter to continue.";
	std::cin.ignore(10000, '\n');
}

bool Stats::record(int r, int c, int val) {
	//cap to 9
	if (i_world[r][c] + val > 9) {
		i_world[r][c] = 9;
		return false;
	}
	i_world[r][c] += val;
	return true;
}