/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'


/* For mathematical structures and methods. */
namespace math
{
	const size_t oo = 0x3f3f3f3f;
	const size_t _oo = 0xcfcfcfcf;

	// TODO: Implement my own root algorithgm
	long double root (long double number, int64_t nth);

	namespace prime
	{
		// Algorithm: Sieve of Eratosthenes.
		// Complexity: O(n log(log(N)))
		// 1st Note: change the following variable's value to any other positive one.
		//           Bigger the number: bigger the binary size (which may break the computation memory limit).
		//           The limit size on C++ is 262,144 bytes (see on https://eel.is/c++draft/implimits)
		//           which is 0.262144 megabytes...
		//           Which after some tests, on this bare-bone program is close to 256,000.
		// 2nd Note: You may change the limit to a greater bytes value with the ‘-fconstexpr-loop-limit=’ flag.
		template<uintmax_t N>
		struct Sieve_of_Eratosthenes
		{
			// Look-up table: plus one because we don't want to access it
			// through position (N >= p >= 1),
			// not index (N > i >= 0).
			array<bool, N + 1> table;

			// Primes list: all primes number until N;
			array<uintmax_t, N + 1> primes;

			// constexpr and initialise table...
			constexpr Sieve_of_Eratosthenes() :
				// Define initial non-primes numbers that are not used in the Sieve (zero and one).
				table{false, false},
				// Pairs and multiples of three are treated a part.
				primes{}
			{
				// Set whole table with truthy.
				for (uintmax_t i = 2; i <= N; ++i)
					table[i] = true;

				for (uintmax_t i = 2, primes_i = 0; i <= N; ++i)
					if (table[i])
					{
						primes[primes_i++] = i;
						for (uintmax_t j = i * i; j <= N; j += i)
							table[j] = false;
					}
			}
		};
	}
	namespace polynomial
	{

		/* Growing-ordered polynomial, so the first
		 * is the highest degree to the last which is
		 * the lowest degree. */
		using polynomial = vector<int64_t>;

		static inline size_t degree(const polynomial& p)
		{
			return p.size() - 1;
		}

		void derivate (polynomial &poly)
		{
			auto N = degree(poly);

			// Remove lowest degree-coeffiecent.
			poly.pop_back();

			// Derivate each term.
			for (size_t i = 0; i < N; i++)
				poly[i] *= int64_t(N - i);
		}

		int64_t evaluate(const polynomial& p, int64_t x)
		{
			int64_t y = 0;
			const size_t N = degree(p);

			for (size_t i = 0; i <= N; ++i)
			{
				y *= x;
				y += p[i];
			}

			return y;
		}

		polynomial operator+ (const polynomial& p, const polynomial& q)
		{
			size_t N = degree(p),
				   M = degree(q);

			polynomial r(max(N, M) + 1, 0);

			for (size_t i = 0; i <= N; ++i)
				r[i] += p[i];

			for (size_t i = 0; i <= M; ++i)
				r[i] += q[i];

			while (not (r.empty() or r.back()))
				r.pop_back();

			if (r.empty())
				r.push_back(0);

			return r;
		}
	}

	namespace base
	{
		char decimal_value (int64_t c)
		{
			if (c >= '0' and c <= '9')
				return char(c) - '0';
			else
				return char(c) - 'A' + 10;
		}

		char base_value(int64_t num)
		{
			if (num >= 0 and num <= 9)
				return (char)(num + '0');
			else
				return (char)(num - 10 + 'A');
		}

		int64_t base_to_decimal (string str, int64_t base)
		{
			int64_t power = 1;
			int64_t num = 0;

			for (int64_t i = int64_t(str.size()) - 1; i >= 0; i--)
			{
				if (decimal_value(str[size_t(i)]) >= base)
					return -1;
				num += decimal_value(str[size_t(i)]) * power;
				power = power * base;
			}
			return num;
		}

		string decimal_to_base (int64_t number, int64_t base)
		{
			string answer = "";

			while (number)
			{
				answer += base_value(char(number % base));
				number /= base;
			}

			reverse(answer.begin(), answer.end());

			return answer;
		}

		string from_base_to_base (int64_t from, int64_t to, string number)
		{
			if (size_t(count(number.begin(), number.end(), '0')) == number.size())
				return "0";

			auto decimal = base_to_decimal(number, from);
			if (decimal < 0)
				return "";

			auto in_base = decimal_to_base(decimal, to);
			return in_base;
		}
	}

	namespace matrix
	{
		using matrix = vector<string>;

		bool is_equal (matrix &a, matrix &b)
		{
			const auto size = a.size();

			if (size not_eq b.size())
				return false;

			for (size_t i = 0; i < size; ++i)
				if (a.at(i) not_eq b.at(i))
					return false;

			return true;
		}

		// TODO: Implement sum of matrix.
		namespace shift
		{
			inline void down (matrix &matrix)
			{
				rotate(matrix.begin(), matrix.begin() + long(matrix.size()) - 1, matrix.end());
			}

			inline void up (matrix &matrix)
			{
				rotate(matrix.begin(), matrix.begin() + 1, matrix.end());
			}

			inline void left (matrix &matrix)
			{
				for (auto &column: matrix)
					rotate(column.begin(), column.begin() + 1, column.end());
			}

			inline void right (matrix &matrix)
			{
				for (auto &column : matrix)
					rotate(column.begin(), column.begin() + long(column.size()) - 1, column.end());
			}
		}
	}
}

namespace string_
{
	inline void erase_wall (string &str, const char &character)
	{
		str.erase(std::remove(str.begin(), str.end(), character), str.end());
	}
}

namespace graph {

	const size_t oo = SIZE_MAX;

	/*
	 * NOTE: Ignores vertex 1.
	 *
	 * Returns the a pair, first the shortest distance, the second the path from S to M.
	 * */
	pair<size_t, vector<int>> dijkstra
		(vector<vector<pair<int, size_t>>> &edges,
		 const size_t &source,
		 const size_t &destiny)
	{
		const size_t n = edges.size() + 1;

		vector<size_t> dist(n, oo);
		vector<int> verts(n, -1);

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> travel;

		travel.emplace(dist[source] = 0, source);

		while(not travel.empty())
		{
			auto [_w, u] = travel.top();
			travel.pop();

			if (_w > dist[size_t(u)])
				continue;

			for (const auto &[v, w] : edges[size_t(u)])
				if (dist[size_t(u)] + w < dist[size_t(v)])
					travel.emplace(dist[size_t(v)] = dist[size_t(u)] + w, v), verts[size_t(v)] = u;
		}

		if (dist[1] == oo)
			return {oo, {}};

		for (int u = 1; u != -1; u = verts[size_t(u)])
			cout << u << ' ';
		return {dist[1], verts};
	}
}

int solve()
{
	size_t n, m;
	cin >> n >> m;

	// ler
	vector<vector<pair<int, size_t>>> edges(n + 1);
	for (size_t i = 1, a, b, w; i <= m; ++i)
	{
		cin >> a >> b >> w;
		edges[a].emplace_back(int(b), w);
		edges[b].emplace_back(int(a), w);
	}

	const auto ans = graph::dijkstra(edges, 1, m);

	if (ans.first == graph::oo)
		return puts("-1"), 0;

	for (auto &path : ans.second)
		cout << path << ' ';
	return cout << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	// cin >> t;
	while (t--)
		solve();
}
