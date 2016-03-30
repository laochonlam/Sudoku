#include "Sudoku.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	Sudoku Sudoku;
	int a=0,b=2;
	Sudoku.readIn();
	Sudoku.printAns();
	printf("\n");
	//Sudoku.changeNum(a,b);
	//Sudoku.changeRow(2,1);
	//Sudoku.changeCol(2,0);
	Sudoku.rotate(1);
	//Sudoku.flip(1);
	Sudoku.printAns();

}
