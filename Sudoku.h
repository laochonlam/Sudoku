

class Sudoku {
	public:
		int ans[9][9];
		int ass;
		int i,j,k;
		Sudoku();
		void giveQuestion();
		void readIn();
		void printAns();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		
};
