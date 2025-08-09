#include "library.hpp"

using namespace std;

int main ()
{
	auto s = read<string>();

	double ans = 0.0;

	cout << fixed << setprecision(17);

	auto n = s.size();

	for (size_t i = 0; i < n; ++i)
		for (size_t j = i + 1; j < n; ++j)
			if (s[i] == 't' and s[j] == 't')
			{
				debug("From", i, j);

				// quantity of t in the range [i, j]
				auto x = count(s.begin() + i, s.end() - (s.size() - (1 + j)), 't');
				debug(x);

				// size of the range [i, j]
				auto tmp = j - i + 1;
				if (tmp == 2)
					continue;
				auto t = double(tmp);
				debug(t);

				auto ans_tmp = (x - 2.0) / (t - 2.0);
				debug(ans_tmp);

				ans = max(ans, ans_tmp);
			}

	cout << ans << endl;
}
