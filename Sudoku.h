

class Sudoku {
	public:
		int ans[9][9];
		int rot[9][9];
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
	private:
		void DFS(int i,int j);
		bool NineTest(int i,int j,int k);
		bool NineTest2(int si,int ei,int sj,int ej,int k);
		bool RowColTest(int i,int j,int k);
};
