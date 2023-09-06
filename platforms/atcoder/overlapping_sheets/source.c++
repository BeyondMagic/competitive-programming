#include <iostream>
#include <array>

using namespace std;

#define endl '\n'
#define MAX 100 + 5

int main()
{
	int n;
	cin >> n;

	array<array<bool, MAX>, MAX> grid;
	for (size_t i = 0; i < MAX; ++i)
		for (size_t j = 0; j < MAX; ++j)
			grid[i][j] = false;

	size_t x_i, x_f, y_i, y_f;
	while (n--)
	{
		cin >> x_i >> x_f >> y_i >> y_f;
		for (auto i = x_i; i < x_f; ++i)
			for (auto j = y_i; j < y_f; ++j)
				grid[i][j] = true;
	}
	size_t c = 0;
	for (size_t i = 0; i < MAX; ++i)
		for (size_t j = 0; j < MAX; ++j)
			if (grid[i][j]) ++c;
	cout << c << endl;

}
