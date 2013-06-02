/************************************************************************************************
Programmer:  Andrew Thompson
Date of completion:  6/1/13
File:  boolMatrix.cpp

The boolMatrix class has 1 private member, bool list[NUM_ROWS][NUM_COLS]), a 2-dimensional Boolean
array.
*************************************************************************************************/


#include <iostream>
#include <iomanip>
#include <cassert>
#include "boolMatrix.h"
using namespace std;


boolMatrix:: boolMatrix() {
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			list[row][col] = false;
		}
	}
}












bool boolMatrix:: get(int someRow, int someCol) const { 
	assert (someRow >= 0 && someRow < NUM_ROWS && someCol >= 0 && someCol < NUM_COLS);
	return list[someRow][someCol];
}












void boolMatrix:: set(int inRow, int inCol, bool inValue) { 
	assert (inRow >= 0 && inRow < NUM_ROWS && inCol >= 0 && inCol < NUM_COLS);
	list[inRow][inCol] = inValue;
}












void boolMatrix:: print() const { 
	cout << "  ";
	for (int col = 0; col < NUM_COLS; col++) {
		cout << col % 10;
	}
	cout << endl;
	for (int row = 0; row < NUM_ROWS; row++) {
		cout << setw(2) << row;
		for (int col = 0; col < NUM_COLS; col++) {
			if (list[row][col]) {
				cout << "*";
			} else {
				cout << " ";
			}
		}
		cout << endl;
	}
}












int boolMatrix:: rowcount(int someRow) const { 
	assert (someRow >= 0 && someRow < NUM_ROWS);
	int sum = 0;
	for (int j = 0; j < NUM_COLS; j++) {
		if (get(someRow, j)) {
			sum++;
		}
	}
	return sum;
}












int boolMatrix:: colcount(int someCol) const { 
	assert (someCol >= 0 && someCol < NUM_COLS);
	int sum = 0;
	for (int i = 0; i < NUM_ROWS; i++) {
		if (get(i, someCol)) {
			sum++;
		}
	}
	return sum;
}












int boolMatrix:: totalcount() const { 
	int sum = 0;
	for (int i = 0; i < NUM_ROWS; i++) {
		sum = sum + rowcount(i);
	}
	return sum;
}