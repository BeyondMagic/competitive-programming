#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	long long D, U, l, t;
	scanf("%lld %lld %lld %lld", &D, &U, &l, &t);

	vector<pair<long long, long long>> S;

	for (long long d, u; scanf("%lld/%lld", &d, &u) != EOF; t--)
		if (D * (100 - l) / 100 > d or U * (100 - l) / 100 > u) // IF INCORRETO, MAS QUE PASSSA, COM TRUNC DE INTEIRO
		// if (100 * (D - d) > l * D or 100 * (U - u) > l * U): IF CORRETO com COMPARAÇÃO ESTRITAMENTE MATEMATICAMENTE CORRETA
			S.emplace_back(d, u);

	sort(begin(S), end(S));

	for (auto &[a, b] : S)
		printf("%lld/%lld\n", a, b);
}
