#include "Sudoku.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>

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
	printf("\n");
	for (i=0;i<9;i++)
	{
		printf("\n");
		for (j=0;j<9;j++)
			printf("%d ",ans[i][j]);
	}
}

////////////////////////////////////////////////////////


bool Sudoku::NineTest(int i,int j,int k){
	if ( i>=0 && i<=2 && j>=0 && j<=2)
		return NineTest2(0,2,0,2,k);
	if ( i>=0 && i<=2 && j>=3 && j<=5)
		return NineTest2(0,2,3,5,k);
	if ( i>=0 && i<=2 && j>=6 && j<=8)
		return NineTest2(0,2,6,8,k);
	if ( i>=3 && i<=5 && j>=0 && j<=2)
		return NineTest2(3,5,0,2,k);
	if ( i>=3 && i<=5 && j>=3 && j<=5)
		return NineTest2(3,5,3,5,k);
	if ( i>=3 && i<=5 && j>=6 && j<=8)
		return NineTest2(3,5,6,8,k);
	if ( i>=6 && i<=8 && j>=0 && j<=2)
		return NineTest2(6,8,0,2,k);
	if ( i>=6 && i<=8 && j>=3 && j<=5)
		return NineTest2(6,8,3,5,k);
	if ( i>=6 && i<=8 && j>=6 && j<=8)
		return NineTest2(6,8,6,8,k);

}

bool Sudoku::NineTest2(int si,int ei,int sj,int ej,int k){
	for (int i = si;i<=ei;i++)
		for (int j = sj;j<=ej;j++)
		{
			if (ans[i][j] == k)
				return false;
		}
	return true;
}

bool Sudoku::RowColTest(int i,int j,int k){
	for (int test = 0; test <9 ;test++)
	{
		if (ans[test][j] == k) return false;
		if (ans[i][test] == k) return false;
	}
	return true;
}





void Sudoku::DFS(int i,int j){
	bool poss = true;
	for (k=1;k<=9;k++)
	{
			poss = NineTest(i,j,k);
			if (poss == true) poss = RowColTest(i,j,k);
			if (poss == true) 
			{
				ans[i][j] = k;
				printAns();
			}
	}
}






void Sudoku::solve(){
	i=0; j=0;
	while (1)
	{
		if ( ans[i][j] == 0)
		{
			DFS(i,j);
			break;
		}
		j++;
		if ( j == 9) { i++; j=0; }
	}


	printAns();
}

//////////////////////////////////////////////////////////

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

void Sudoku::rotate(int n){
	n = n % 4;
	int row,col;
	for (k=0;k<n;k++)
	{
		row = 0;col = 0;
		for (i=0;i<9;i++)
			for (j=8;j>=0;j--)
			{
				rot[row][col] = ans[j][i];
				col++;
				if (col == 9) { row++; col = 0;} 
			}
	
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			ans[i][j] = rot[i][j];
	}
}



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
	srand(time(NULL));
	changeNum(rand()%9,rand()%9);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);	
}
