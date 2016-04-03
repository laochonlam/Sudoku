#include "Sudoku.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

Sudoku::Sudoku(){
	soluation = 0;	
}

int Sudoku::Counter(int i ){
	int last = 0;
	for (int eden = 0;eden<9;eden++)
		last = last + print[eden][8];
	return (45 - last);
}

void Sudoku::giveQuestion(){ 
	int c[9][9] = {{5,3,4,6,7,8,9,1,2},
				   {6,7,2,1,9,5,3,4,8},
				   {1,9,8,3,4,2,5,6,7},
				   {8,5,9,7,6,1,4,2,3},
				   {4,2,6,8,5,3,7,9,1},
				   {7,1,3,9,2,4,8,5,6},
				   {9,6,1,5,3,7,2,8,4},
				   {2,8,7,4,1,9,6,3,5},
				   {3,4,5,2,8,6,1,7,9}};

	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
			ans[i][j] = c[i][j];

	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);

	

	for (i=0;i<0;i++)
		for (j=0;j<9;j++)
			c[i][j] = ans[i][j];
		
	for (i=0;i<50;i++)
		ans[rand()%9][rand()%9] = 0;

	for (i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}
}


void Sudoku::readIn(){
	for (i = 0;i<9;i++)
		for (j = 0;j<9;j++)
			scanf("%d",&ans[i][j]);
}

void Sudoku::printAns(){
	cout<<endl;
	for (i=0;i<9;i++)
	{

		for (j=0;j<9;j++)
			printf("%d ",print[i][j]);
		printf("\n");
	}
}



bool Sudoku::NineTest(int i,int j,int k,int aa){
	if ( i>=0 && i<=2 && j>=0 && j<=2)
		return NineTest2(0,2,0,2,k,aa);
	if ( i>=0 && i<=2 && j>=3 && j<=5)
		return NineTest2(0,2,3,5,k,aa);
	if ( i>=0 && i<=2 && j>=6 && j<=8)
		return NineTest2(0,2,6,8,k,aa);
	if ( i>=3 && i<=5 && j>=0 && j<=2)
		return NineTest2(3,5,0,2,k,aa);
	if ( i>=3 && i<=5 && j>=3 && j<=5)
		return NineTest2(3,5,3,5,k,aa);
	if ( i>=3 && i<=5 && j>=6 && j<=8)
		return NineTest2(3,5,6,8,k,aa);
	if ( i>=6 && i<=8 && j>=0 && j<=2)
		return NineTest2(6,8,0,2,k,aa);
	if ( i>=6 && i<=8 && j>=3 && j<=5)
		return NineTest2(6,8,3,5,k,aa);
	if ( i>=6 && i<=8 && j>=6 && j<=8)
		return NineTest2(6,8,6,8,k,aa);

}

bool Sudoku::NineTest2(int si,int ei,int sj,int ej,int k,int aa){
	for (int i = si;i<=ei;i++)
		for (int j = sj;j<=ej;j++)
		{

			if (ans[i][j] == k) aa++;
			if (aa>=2) return false;
		}
	return true;
}

bool Sudoku::RowColTest(int i,int j,int k){
	for (int test = 0; test <9 ;test++)
	{
		if ( test != i)
			if (ans[test][j] == k) return false;
		if ( test != j)
			if (ans[i][test] == k) return false;
	}
	return true;
}





void Sudoku::DFS(int i,int j){
	bool poss = true;
	bool flag = false;
	int row,col;
	int p;
	int yo,ya; 
	int correct = 0;
	for (int k=1;k<=9;k++)
	{
			if (soluation > 1) return;
			poss = true; flag = false;
			poss = NineTest(i,j,k,1);
			if (poss == true) poss = RowColTest(i,j,k);
			if (poss == true) 
			{
				ans[i][j] = k;

				row = i; col = j+1;
				if ( col == 9) { col = 0; row++;}
				while (flag == false)
				{
					if ( ans[row][col] == 0)
					{  DFS(row,col); flag = true; };
					col++;
						
					if (col == 9) {col = 0;row++;}
					if (col == 0 && row == 9) 
					{
						{
								soluation ++;
					   	 	for (int x=0;x<9;x++)
								for (int y=0;y<9;y++)
									print[x][y] = ans[x][y];	

						}
					}
					
					
				}
			}
	}
	ans[i][j] = 0;
}

void Sudoku::solve(){
	bool tester;
	int doo = 0;
	for (i=0;i<9;i++)
		for (j=0;j<9;j++)
		{
			if (ans[i][j] != 0)
			{
				tester = true;
				tester = RowColTest(i,j,ans[i][j]);
				if (tester == true)
				tester = NineTest(i,j,ans[i][j],0);
				else { doo = 1; break;}
				if (tester == false){ soluation = 0; doo  = 1; break;}
			}
		}

	if (doo == 0)
	{
	i=0; j=0;
	int help = 0; int pascal,python;
	while ( i<9 )
	{
		if ( ans[i][j] == 0)
		{
			DFS(i,j);
			break;
		} else { help++; }
		j++;
		if ( j == 9) { i++; j=0; }
	}

	if (soluation == 1)
		if (print[8][8] == 0)
			print [8][8] = Counter(8);
	
	if (help == 81)
	{
		for (pascal=0;pascal<9;pascal++)
			for (python=0;python<9;python++)
				print[pascal][python] = ans[pascal][python];
		soluation++;
	}

	}
	if (soluation > 1 )
		cout<<"2";
	if (soluation == 1)
	{
		cout<<"1";
		printAns();
	}
	if (soluation == 0)
		cout<<"0";
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

void Sudoku::rotate(int n){
	n = n % 4;
	int row,col;
	for (int count=0;count<n;count++)
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
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
	for (i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
			printf("%d ",ans[i][j]);
		printf("\n");
	}				
}
