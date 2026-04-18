#include "library.hpp"

using namespace std;

int k = 0; // number of valid arrangements

/*
A function like solve(row) would try to place a queen in the row-th row.

Base Case: If you successfully place a queen in the last row (i.e., row == 8), you've found one valid solution. Increment your answer count and return.

Recursive Step: In the solve(row) function, loop through all 8 columns. For each column, if placing a queen at (row, column) is safe, place it and then recursively call solve(row + 1).

"Backtrack": After the recursive call returns, you must undo your choice (remove the queen) so you can try placing it in the next column of the current row.
*/
void solve(int row, vector<bool> &cols, vector<bool> &d1, vector<bool> &d2) {
	if (row == 8) {
		k++;
		return;
	}
	for (int col = 0; col < 8; col++) {
		if (!cols[col] && !d1[row + col] && !d2[row - col + 7]) {
			cols[col] = d1[row + col] = d2[row - col + 7] = true;
			solve(row + 1, cols, d1, d2);
			cols[col] = d1[row + col] = d2[row - col + 7] = false; // backtrack
		}
	}
}

int main ()
{
	cout << ":)" << endl;
}
