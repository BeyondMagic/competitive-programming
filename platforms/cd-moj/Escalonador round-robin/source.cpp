/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define space ' '
#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

#define INF 1000000000

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
 * Read pair of perhaps different somethings from standard input and return it.
 */
template<
	typename T,
	typename K
>
inline auto
read ()
-> pair<T, K>
{
	pair<T, K> P;
	cin >> P.first >> P.second;
	return P;
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

// Deve ser resolvido em menos de 2 segundos.
int main ()
{
	fast_io();

	// algoritmo d. berkley
	auto [N, quantum] = read<int, int>();

	// { (time_1, pid_1), (time_2, pid_2), ... }
	vector<pair<int, int>> P(N);
	for (auto &[pid, temp] : P)
		cin >> pid >> temp,
		temp *= 1000; // 1 segundo

	for (int j = 0, total = 0; N; j = j == N ? 0 : j)
	{
		auto &[id, time] = P[j];

		total += quantum;
		time -= quantum;

		// can't clean
		if (time > 0)
			++j;

		else if (time != -INF)
		{
			total += time;
			print << id << space << '(' << total << ')' << endl;
			// time = -INF;
			P.erase(P.begin() + j);

			--N;
		}
	}
	
	// debug(P);
}
