#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto [a, b, c] = read<int, int, int>(); // nao visitados por cad aum dos amigos
	auto M = map<int, int>();
	int x;
	auto K = vector<int>();

	while (cin >> x)
		if (++M[x] == 3)
			K.emplace_back(x);

	sort(begin(K), end(K));
	cout << K << endl;
}
