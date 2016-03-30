#include "Sudoku.h"
#include <cstdio>
#include <iostream>

Sudoku::Sudoku(){
	
}

void Sudoku::giveQuestion(){
}


void Sudoku::readIn(){
	for (i = 0;i<9;i++)
		for (j = 0;j<9;j++)
			scanf("%d",&ans[i][j]);
}

void Sudoku::printAns(){
	for (i=0;i<9;i++)
	{
		printf("\n");
		for (j=0;j<9;j++)
			printf("%d ",ans[i][j]);
	}
}

void Sudoku::solve(){
}

void Sudoku::changeNum(int a,int b){
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
		{
			if (ans[i][j] == a)  ans[i][j] = b;
			else if (ans[i][j] == b) ans[i][j] = a;
		}
}

void Sudoku::changeRow(int a,int b){
	if (a == 1) a = 3;
	if (b == 1) b = 3;
	if (a == 2) a = 6;
	if (b == 2) b = 6;

	for (i=a;i<3+a;i++)
		for (j=0;j<9;j++)
		{
			 ass = ans[i][j];
			 ans[i][j] = ans[b+(i-a)][j];
			 ans[b+(i-a)][j] = ass;
		}
}

void Sudoku::changeCol(int a,int b){
	if (a == 1) a = 3;
	if (b == 1) b = 3;
	if (a == 2) a = 6;
	if (b == 2) b = 6;

	for (i=0;i<9;i++)
		for (j=a;j<3+a;j++)
		{
			ass = ans[i][j];
			ans[i][j] = ans[i][b+(j-a)];
			ans[i][b+(j-a)] = ass;
		}
}

void Sudoku::rotate(int n){}



void Sudoku::flip(int n){
	if ( n == 0)
	{
		for (i=0;i<=3;i++)
			for (j=0;j<9;j++)
				{
					ass = ans[i][j];
					ans[i][j] = ans[(8-i)][j];
					ans[(8-i)][j] = ass;
				}
	}
	else 
	{
		for (i=0;i<9;i++)
			for (j=0;j<=3;j++)
			{
				ass = ans[i][j];
				ans[i][j] = ans [i][8-j];
				ans [i][8-j] = ass;
			}
	}

}

void Sudoku::transform(){
}
