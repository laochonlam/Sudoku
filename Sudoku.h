

class Sudoku {
	public:
		int ans[9][9];
		int rot[9][9];
		int print[9][9];
		int ass;
		int i,j;
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
		int soluation;
		void DFS(int i,int j);
		bool NineTest(int i,int j,int k,int aa);
		bool NineTest2(int si,int ei,int sj,int ej,int k,int aa);
		bool RowColTest(int i,int j,int k);
		int Counter(int i);
};
