#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	vector<string> A;
	if (n mod 3 == 0)
		A.emplace_back("Troca do soro");
	if (n mod 5 == 0)
		A.emplace_back("Injecao de antibioticos");
	if (n mod 12 == 0)
		A.emplace_back("Reavaliacao");
	if (A.empty())
		A.emplace_back("Monitoramento dos sinais vitais");
	cout << n << " horas de tratamento:" << endl;
	for (auto &a : A)
		cout << a << endl;
}
