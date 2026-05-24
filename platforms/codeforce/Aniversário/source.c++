#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto N = read<int>();
	auto P = vector<pair<string, int>>(N);
	for (auto &[n, a] : P)
		cin >> n >> a;

	auto S = set<tuple<string, string, int, int>>();

	for (int i = 0; i < 100; ++i)
	{
		for (auto &[An, Aa] : P)
		{
			if (Aa + i > 99)
				continue;

			auto Adec = (Aa + i) / 10;
			auto Aunit = (Aa + i) % 10;

			for (auto &[Bn, Ba] : P)
			{
				if (Ba + i > 99 or Bn == An)
					continue;

				auto Bdec = (Ba + i) / 10;
				auto Bunit = (Ba + i) % 10;

				if (Adec == Bunit and Aunit == Bdec)
				{
					auto smaA = min(Ba + i, Aa + i);
					auto bigB = max(Ba + i, Aa + i);

					if (S.count(make_tuple(An, Bn, smaA, bigB)))
						continue;
					S.emplace(Bn, An, smaA, bigB);
					S.emplace(An, Bn, smaA, bigB);
					cout << "Em " << i << " anos " << An << " faz " << Aa + i << " e " << Bn << " " << Ba + i << endl;
				}
			}
		}

	}
}
