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

static constexpr auto &print = cout;
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
ostream& operator<<(ostream& out, const vector<int>& vec)
{
	const auto vec_end = vec.end();
	const auto before = prev(vec_end);

	for (auto it = vec.begin(); it < vec_end; ++it)
		out << *it << (it == before ? endl : ' ');

	return out;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> A{-1};

	const auto Q = read<int>();
	for (int i = 1; i <= Q; ++i)
	{
		const auto T = read<int>();
		if (T == 1)
		{
			const auto X = read<int>();
			A.emplace_back(X);
		} else {
			const auto K = read<int>();
			print << A.at(A.size() - K) << endl;
		}
	}
}
