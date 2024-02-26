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
template<
	typename T,
	enable_if_t<is_same_v<T, int>, bool> = true
>
inline auto
read ()
-> T
{
	T number;
	cin >> number;
	return number;
}

/*
 * Print a vector of integer separated by a character.
 */
inline auto
print (
		const vector<int> &vec,
		const char &separator = ' ',
		const char &end = '\n')
-> void
{
	const auto vec_end = vec.end();
	const auto before = prev(vec_end);

	for (auto it = vec.begin(); it < vec_end; ++it)
		cout << *it << (it == before ? end : separator);
}


int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto A = read<int>();
	auto B = read<int>();
	auto D = read<int>();

	vector<int> V;
	for (auto x = A; x <= B; x += D)
		V.push_back(x);

	print(V);
}
