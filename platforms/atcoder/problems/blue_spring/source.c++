#include <algorithm>
#include <array>
#include <cinttypes>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

#define endl '\n'

typedef uint64_t big;

int main() {
	int n, d;
	ll f[201000], p;
	// le os numeros
	scanf("%d%d%lld", &n, &d, &p);

	// le quanto csuta cada dia
	for (int i = 1; i <= n; i++)
		scanf("%lld", &f[i]);

	// ordena do menor pro maior
	sort(f + 1, f + n + 1);

	for (int i = 1; i <= n; i++)
		f[i] += f[i - 1];

	ll ans = 1e18;

	for (int i = 0; i * d <= n + d; i++)
		ans = min(ans, f[max(0, n - i * d)] + p * i);

	return printf("%lld", ans), 0;
}
