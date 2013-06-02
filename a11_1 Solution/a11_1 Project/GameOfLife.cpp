/************************************************************************************************
Programmer:  Andrew Thompson
Date of completion:  6/1/13
File:  GameOfLife.cpp

This program plays the Game of Life for a number of generations determined by the user.  At the 
end of the game, the game board is displayed with living cells represented by "*" and empty cells
by " ".  Statistics are displayed regarding the number of livings cells in specific regions 
of the board and the entire board.
*************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cassert>
#include "boolMatrix.h"
using namespace std;


const int STAT_ROW = 10; // row number used in statistical summary
const int STAT_COL = 10; // column number used in statistical summary
const int TWO = 2; // number used to evaluate viability of life
const int THREE = 3; // number used to evaluate viability of life

void getInitialData(boolMatrix& dish);
void playGame(int n, boolMatrix& dish);
void playOneRound(boolMatrix& dish);
bool getFutureValue(boolMatrix& dish, int& row, int& col);
int countNeighbors(boolMatrix& dish, int& row, int& col);
void copyDish(boolMatrix dish1, boolMatrix& dish2);
void printResults(boolMatrix& dish);

int main() {
	
	int rounds;
	boolMatrix petriDish;

	cout << "This game is a computer simulation of the life and death events in a population " <<
			"of single-cell organisms.\n\nEach position in a two-dimensional Petri dish " <<
			"can support one cell. The program determines whether each position will be able " <<
			"to support life in the next generation.  Live cells are represented by asterisks.\n\n";

	cout << "Enter number of generations: " ;
	cin >> rounds;
	
	getInitialData(petriDish);
	playGame(rounds, petriDish);
	printResults(petriDish);

	system("pause");
}












/************************************************************************************************
Pre:  A boolMatrix object (the Petri dish) has been instantiated.
Post:  Array elements of the boolMatrix object have been populated with values from an external
file.
************************************************************************************************/
void getInitialData(boolMatrix& dish){

	int row, column;
	ifstream infile("data.txt");
	
	assert(infile);

	infile >> row >> column;
	while (infile) {
		dish.set(row, column, true);
		infile >> row >> column;
	}
	
	infile.close();
}












/************************************************************************************************
Pre:  A boolMatrix object (the Petri dish) has been instantiated.  The player has specified the
number of future generations (n) to play.
Post:  Array elements of the boolMatrix object have been populated with values n generations 
later.
************************************************************************************************/
void playGame(int n, boolMatrix& dish) {

	cout << endl;
	for (int round = 1; round <= n; round++) {
		playOneRound(dish);
	}
}












/************************************************************************************************
Pre:  A boolMatrix object (the Petri dish) has been instantiated.  The player has specified the
number of future generations to play.  A for loop has invoked one round of game play.
Post:  Array elements of the boolMatrix object in generation x have been updated with values for
generation x + 1.

Since all births and deaths occur simultaneously, a temporary Petri dish is created to 
store the future values of each cell.  The values in the original dish are left undisturbed so
as to calculate each cell's future value based on the current neighbors, not on future neighbors.
Once all future values have been calculated, they are copied over to the original Petri dish 
simultaneously. 
************************************************************************************************/
void playOneRound(boolMatrix& dish) {

	boolMatrix temp;  // temporary boolMatrix object

	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			temp.set(row, col, getFutureValue(dish, row, col));
		}
	}

	copyDish(temp, dish);  
}












/************************************************************************************************
Pre:  A boolMatrix object has been instantiated and populated with initial values from an 
external file.  Arguments for a particular row and column have been passed.
Post:  Using the following rules, the value in the cell during the next generation has been
returned.

A) If the cell is currently empty: 
1. If the cell has exactly three living neighbors, it will come to life in the next generation.
2. If the cell has any other number of living neighbors, it will remain empty.

B) If the cell is currently living: 
1. If the cell has one or zero living neighbors, it will die of loneliness in the next generation.
2. If the cell has four or more living neighbors, it will die of overcrowding in the next generation.
3. If the cell has two or three neighbors, it will remain living.
************************************************************************************************/
bool getFutureValue(boolMatrix& dish, int& row, int& col) {

	bool status = false;

	if (dish.get(row, col) && (countNeighbors(dish, row, col) == TWO) || 
		countNeighbors(dish, row, col) == THREE) {
		status = true;
	}
	return status;
}












/************************************************************************************************
Pre:  A boolMatrix object has been instantiated.  The location of a specific cell has been passed
as a pair of arguments (row and col).
Post:  A count of living cells in the 8 cells surrounding the cell at row and col has been 
returned.  If row and/or col is on the edge of the Petri dish (game board), the spaces outside
the Petri dish are ignored for the purposes of the count.  The value in the cell at row and col
is also disregarded.
************************************************************************************************/
int countNeighbors(boolMatrix& dish, int& row, int& col) {

	int neighbors = 0;
	
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((row + i >= 0) && (row + i < NUM_ROWS) && (col + j >= 0) && (col + j < NUM_COLS) && 
				!(i == 0 && j == 0)) {
				if (dish.get(row + i, col + j)) {
					neighbors++;
				}
			}
		}
	}

	return neighbors;
}












/************************************************************************************************
Pre:  Two boolMatrix objects have been instantiated.  Both have been passed as arguments (dish1
and dish2).
Post:  The values in dish1 have been copied over to dish2.
************************************************************************************************/
void copyDish(boolMatrix dish1, boolMatrix& dish2) {

	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			dish2.set(i, j, dish1.get(i, j));
		}
	}
}












/************************************************************************************************
 Pre:  A boolMatrix object has been instantiated to represent the Petri dish.
 Post:  The values in the Petri dish have been displayed as "*" for living cells and " " for
 empty cells.  The count of living cells in a particular row, a particular column, and the entire
 Petri dish have been displayed.
************************************************************************************************/
void printResults(boolMatrix& dish) {

	dish.print();
	cout << "Total alive in row " << STAT_ROW << " = " << dish.rowcount(STAT_ROW) << endl;
	cout << "Total alive in col " << STAT_COL << " = " << dish.colcount(STAT_COL) << endl;
	cout << "Total alive = " << dish.totalcount() << endl;
}