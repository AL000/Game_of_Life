/************************************************************************************************
Programmer:  Andrew Thompson
Date of completion:  6/1/13
File:  boolMatrix.h

The boolMatrix class has 1 private member representing a 2-dimensional Boolean array.

There is a default constructor that sets all array elements to false, a getter, and a setter.  
A print function displays the array elements in rows and columns as "*" for true and " " for false.

rowcount, colcount, and totalcount display the total number of true values in a given row, a
given column, or the total array, respectively.

  

Public Members:

default constructor:  boolMatrix()
Post: A boolMatrix object (2-dimensional Boolean array) with all array elements initialized to 
false is instantiated.

getter:  get(int someRow, int someCol)
Pre: A boolMatrix object has been instantiated and the arguments someRow and someCol have been passed.
Post:  The current value (true or false) of a single array element at the specified row and column is
returned.  This function exits the program if either the row or column is out-of-bounds.

setter:  set(int inRow, int inCol, bool inValue)
Pre: A boolMatrix object has been instantiated and the arguments someRow, someCol, and inValue have 
been passed.
Post:  The value (true or false) of a single array element at the specified row and column has been
replaced with inValue.  This function exits the program if either the row or column is out-of-bounds.

print()
Pre:  A boolMatrix object (2-dimensional Boolean array) has been instantiated.
Post:  The contents of the array, including the row and column indices, are displayed.  Each space 
in the array (grid) is represented by "*" for true or " " for false.

rowcount(int someRow)
Pre:  A boolMatrix object has been instantiated, and the argument someRow has been passed.
Post:  The number of true values that exist in someRow is returned. This function exits the program 
if someRow is out-of-bounds.

colcount(int someCol)
Pre:  A boolMatrix object has been instantiated, and the argument someCol has been passed.
Post:  The number of true values that exist in someCol is returned. This function exits the program 
if someCol is out-of-bounds.

int totalcount() 
Pre:  A boolMatrix object has been instantiated.
Post:  The number of true values that exist in the entire object (2-dimensional Boolean array) is 
returned.

*************************************************************************************************/

#ifndef BOOLMATRIX_H
#define BOOLMATRIX_H

const int NUM_ROWS = 20;
const int NUM_COLS = 20;

class boolMatrix {

    public:
        boolMatrix(); 
		bool get(int someRow, int someCol) const;
		void set(int inRow, int inCol, bool inValue); 
        void print() const; 
		int rowcount(int someRow) const; 
		int colcount(int someCol) const; 
		int totalcount() const; 

    private:
		bool list[NUM_ROWS][NUM_COLS];

};

#endif
