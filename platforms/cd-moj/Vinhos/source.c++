#include "library.hpp"

using namespace std;

int main()
{
	fast_io();

	auto n = read<int>();
	auto V = priority_queue<int, vector<int>, greater<int>>();

	while (n--)
	{
		auto c = read<string>();
		if (c == "?")
		{
			if (V.empty())
				cout << -1 << endl;
			else
			{
				auto v = V.top();
				cout << v << endl;
				V.pop();
			}
		} else {
			auto v = read<int>();
			V.emplace(v);
		}
	}
}
