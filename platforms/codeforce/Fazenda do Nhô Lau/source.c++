#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	auto px = -1, py = -1,
		 qx = 1, qy = 1;

	for (int x, y; n--;)
	{
		cin >> x >> y;
		px = min(px, x - 1);
		py = min(py, y - 1);
		qx = max(qx, x + 1);
		qy = max(qy, y + 1);
	}

	cout << px << space << py << endl;
	cout << qx << space << qy << endl;
}
