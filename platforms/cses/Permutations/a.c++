#include <bits/stdc++.h>

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

using namespace std;

constexpr auto &print = cout;

/* Make code more humane. */
#define endl '\n'
#define space ' '
#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

/* Disconnect C. */
inline auto
fast_io (void)
-> void {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

/*
 * Read number or string from standard input and return it.
 */
template<
	typename T,
	enable_if_t<(is_arithmetic<T>::value or is_same_v<T, string>), bool> = true
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
 * Read tuple of (possible) diferent types from standard input and return it.
 */
template<
	typename... types,
	enable_if_t<(sizeof...(types) > 1), bool> = true
>
inline auto
read ()
-> tuple<types...>
{
	auto some_function = [](auto&& x)
	{
		cin >> x;
	};

	tuple<types...> T;
	apply(
		[&](auto &...x) {
			(..., some_function(x));
		}, T
	);

	return T;
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


using namespace std;

// Minha intuição está dizendo que a resposta será alternada.
int main ()
{
	auto N = read<int>();

	if (N == 1)
		return print << 1 << endl, 0;

	vector<int> perm;

	int pr = 0;
	
	for (int s = 1, k = N; s < k; s += 2)
	{
		perm.emplace_back(k - s);

		if (abs((k - s) - pr) == 1)
			return print << "NO SOLUTION" << endl, 0;

		pr = k - s;
	}

	for (int s = 0, k = N; s < k; s += 2, pr = k - s)
	{
		perm.emplace_back(k - s);

		if (abs((k - s) - pr) == 1)
			return print << "NO SOLUTION" << endl, 0;

		pr = k - s;
	}

	for (int i = 0; i < N; ++i)
		print << perm[i] << (i + 1 == N ? endl : space);
}
