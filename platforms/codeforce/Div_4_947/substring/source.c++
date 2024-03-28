/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define space ' '

static constexpr auto &print = cout;

inline auto
fast_io (void)
-> void {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

/*
 * Read integer from standard input and return it.
 */
template<
	typename T,
	enable_if_t<is_arithmetic<T>::value, bool> = true
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
 * Read string from standard input and return it.
 */
template<
	typename T,
	enable_if_t<is_same_v<T, string>, bool> = true
>
inline auto
read ()
-> T
{
	T str;
	cin >> str;
	return str;
}

/*
 * Print a vector of key data structures separated by a character and ended by a special character.
 */
template<
	typename T
>
ostream& operator<<(ostream& out, const vector<T>& vec)
{
	const auto vec_end = vec.end();
	const auto before = prev(vec_end);

	for (auto it = vec.begin(); it < vec_end; ++it)
		out << *it << (it == before ? endl : space);

	return out;
}

int main ()
{
	fast_io();

	auto T = read<int>();

	while (T--)
	{
		auto N = read<int>();
		auto S = read<string>();

		unordered_set<string> processed;

		auto size_found = 0;

		for (auto size = 1; size * 2 <= N and not size_found; ++size)
		for (int i = 0; i < N; ++i)
		{
			auto orig = S.substr(i, size);

			auto s = orig;

			if (processed.contains(s))
				continue;

			processed.insert(s);

			while (s.length() < S.length())
				s += orig;

			if (s.length() != S.length())
				continue;

			// calculate difference of charcters.
			int qnt = 0;
			for (int j = 0; j < N; ++j)
				if (s[j] != S[j])
					++qnt;

			if (qnt <= 1)
			{
				size_found = size;
				break;
			}
		}

		print << (size_found ? size_found : N) << endl;
	}
}
