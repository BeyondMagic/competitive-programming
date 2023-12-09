#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

/*
 * Method of Fermat for Integer Factorization.
 * O(|P - Q)
 */
template<typename T>
[[nodiscard("Use the return divisors of the number.")]]
constexpr
auto factor_fermat (T n)
{
	static_assert(is_integral<T>::value, "Must be a integer.");
	T a = T(ceil(sqrt(n)));
	T b2 = a * a - n;
	T b = T(round(sqrt(b2)));
	while (b * b != b2)
	{
		++a;
		b2 = a * a - n;
		b = T(round(sqrt(b2)));
	}

	return make_pair(a - b, a + b);
}

/*
 * Transform number into binary representation.
 */
template<typename T>
[[nodiscard("Use the return value of the binary representation of a number.")]]
inline
constexpr
auto to_binary (T A)
{
	static_assert(is_arithmetic<T>::value, "Must be a number.");
	long long unsigned int R = 0;
	memcpy(&R, &A, sizeof(T));
	return bitset<sizeof(T) << 3>(R);
}

/*
 * Calculate a^n % m
 * Complexity: O(log n)
 */
// binary_expo

/* Growing-ordered polynomial, so the first
 * is the highest degree to the last which is
 * the lowest degree. */
template<typename T>
struct polynomial
{
	static_assert(is_arithmetic<T>::value, "Must be a number.");
	vector<T> coefficients;

	polynomial() : coefficients(1, 0){};

	constexpr inline auto degree() const
	{
		constexpr auto size = coefficients.size();
		return size ? size - 1 : size;
	}

	// Derivate (prefix operator).
	polynomial& operator--()
	{
		const auto N = degree(this);

		// Remove lowest degree-coeffiecent.
		coefficients.pop_back();

		// Derivate each term.
		for (size_t i = 0; i < N; ++i)
			coefficients.at(i) *= reinterpret_cast<T>(N - i);
	}

	// Evaluate.
	polynomial& operator()(T a)
	{
		T result = 0;
		const auto N = degree(this);

		// P(x) = dx³ + cx² + bx¹ + a
		// r = d 
		for (size_t i = 0; i < N; ++i)
			result *= a,
			result += coefficients[i];

		return result;
	}

	/*
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
	}*/
};

int main ()
{
	long long a;
	float b;
	cin >> a >> b;

	cout << sizeof(a) << endl;
	cout << to_binary(a) << endl;
	cout << to_binary(b) << endl;
	auto result = factor_fermat(a);
	cout << result.first << " " << result.second << endl;
}
