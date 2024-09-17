#include "library.hpp"

using namespace std;

int main ()
{
	auto n = read<size_t>();
	vector<size_t> ids(n);
	for (auto &id : ids)
		cin >> id;

	queue<tuple<size_t, size_t, vector<size_t>>> Q;
	for (size_t i = 0; i < n; ++i)
	{
		vector<size_t> C(ids[i]);
		for (auto &c : C)
			cin >> c;

		Q.emplace(i + 1, ids[i], C);
	}

	for (int i = 0, ans = 0; not Q.empty(); i = 0)
	{
		auto [id, k, C] = Q.front();
		Q.pop();

		// trocar para for
		while (k and C[i] != 1)
			k--,
			ans += 10,
			++i;

		if (not k)
			print << id << " (" << ans << ")\n";
		else
		{
			C[i] = 0;
			for (size_t j = 0; j < k; ++j)
				C[j] = C[i++];

			Q.emplace(id, k, C);
		}

	}

}
