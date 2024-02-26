/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

#define endl '\n'

/*
 * Read integer from standard input and return it.
 */
template<typename T, enable_if_t<is_same_v<T, int>, bool> = true>
inline auto
read ()
-> T
{
	T number;
	cin >> number;
	return number;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto A = read<int>();
	auto B = read<int>();
	auto D = read<int>();

	for (auto x = A; x <= B; x += D)
		cout << x << (x == B ? endl : ' ');
}
