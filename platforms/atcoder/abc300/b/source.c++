#include "library.hpp"

using namespace std;

vector<string> A, B;
int h, w;

using matrix = vector<string>;

namespace shift
{
	inline void down (matrix &matrix)
	{
		rotate(matrix.begin(), matrix.begin() + long(matrix.size()) - 1, matrix.end());
	}

	inline void up (matrix &matrix)
	{
		rotate(matrix.begin(), matrix.begin() + 1, matrix.end());
	}

	inline void left (matrix &matrix)
	{
		for (auto &column : matrix)
			rotate(column.begin(), column.begin() + 1, column.end());
	}

	inline void right (matrix &matrix)
	{
		for (auto &column : matrix)
			rotate(column.begin(), column.begin() + long(column.size()) - 1, column.end());
	}
}

bool is_equal() {
	for (int i = 0; i < h; ++i)
		if (A[i] != B[i])
			return false;
	return true;
}

int main ()
{
	cin >> h >> w;
	A.resize(h);
	B.resize(h);
	for (auto &a : A)
		cin >> a;
	for (auto &b : B)
		cin >> b;

	debug(A);
	debug(B);

	if (is_equal())
		return print << "Yes" << endl, 0;

	for (int i = 0; i < h; ++i)
	{
		shift::down(A);
		if (is_equal())
			return print << "Yes" << endl, 0;

		for (int j = 0; j < w; ++j)
		{
			shift::left(A);
			if (is_equal())
				return print << "Yes" << endl, 0;
		}
	}

	print << "No" << endl;
}
