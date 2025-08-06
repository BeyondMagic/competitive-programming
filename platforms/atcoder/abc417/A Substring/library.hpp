#include <bits/stdc++.h>

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

using namespace std;

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

using string_line = basic_string<int>;

/*
 * Read entire line from standard input and return it.
 */
template<
	typename T,
	enable_if_t<(is_same_v<T, string_line>), bool> = true
>
inline auto
read ()
-> T
{
	string s;
	getline(cin, s);
	return s;
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
	T alpha;
	cin >> alpha;
	return alpha;
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

/**
 * Calculate the prefix sum of a vector/array.
 * Prefix sum is a technique to calculate the cumulative sum of elements in a sequence.
 * It allows you to efficiently calculate the sum of any subarray.
 */
template<
	typename T,
	enable_if_t<(is_arithmetic<T>::value), bool> = true
>
inline auto
prefix_sum(const vector<T>& vec)
-> vector<T>
{
	const auto n = vec.size();
	vector<T> prefix(n);
	prefix[0] = vec[0];
	for (size_t i = 1; i < n; ++i)
		prefix[i] = prefix[i - 1] + vec[i];
	return prefix;
}

/**
 * Calculate the difference array of a vector/array.
 * The difference array is a way to represent the changes in a sequence.
 * It allows you to efficiently perform range updates and queries.
*/
template<
	typename T,
	enable_if_t<(is_arithmetic<T>::value), bool> = true
>
inline auto
difference_array(const vector<T>& vec)
-> vector<T>
{
	const auto n = vec.size();
	vector<T> diff(n);
	diff[0] = vec[0];
	for (size_t i = 1; i < n; ++i)
		diff[i] = vec[i] - vec[i - 1];
	return diff;
}

/**
 * This function computes the power of a base raised to an exponent with an optional modulus.
 * Works for integer, floating-point, complex numbers, usize, etc.
 */
template <
	typename T,
	enable_if_t<(is_arithmetic<T>::value), bool> = true
	// std::enable_if_t<std::is_integral_v<T>,int> = 0
>
inline auto
power(
	T base,
	size_t exponent,
	T modulus = std::numeric_limits<T>::max())
	-> T
{
	T result = 1;
	bool do_mod = (modulus != std::numeric_limits<T>::max());

	if (do_mod)
		base %= modulus;

	while (exponent > 0)
	{
		if (exponent & 1)
		{
			result = result * base;
			if (do_mod)
				result %= modulus;
		}
		base = base * base;
		if (do_mod)
			base %= modulus;
		exponent >>= 1;
	}

	return result;
}
