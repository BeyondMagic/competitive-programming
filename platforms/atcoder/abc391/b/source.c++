#include "library.hpp"

using namespace std;

int n, m;
vector<string> s, t;

int main ()
{
	cin >> n >> m;
	s.resize(n);
	t.resize(m);

	for (auto &r : s)
		cin >> r;

	for (auto &r : t)
		cin >> r;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int ti = 0, tj = 0;

			if (s[i][j] == t[ti][tj])
			{
				//debug(i, j, ti, tj);

				bool ok = true;

				if (m != 1)
					while (ti < m and ok)
					{
						//debug(ti);
						while (tj < m and ok)
						{
							if (s[i + ti][j + tj] != t[ti][tj])
								ok = false;
							//debug(i + ti, j + tj, ti, tj);
							//debug(s[i + ti][j + tj], t[ti][tj]);
							++tj;
						}
						++ti;
						tj = 0;
					}


				if (ok)
					return print << i + 1 << space << j + 1 << endl, 0;
			}
		}
	}

	assert(false);
}
