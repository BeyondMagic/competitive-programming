#include "library.hpp"

using namespace std;

template<typename T>
bool are_nearly_equal (T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
{
	// 1. Handle exact equality (includes infinities)
	if (a == b)
		return true;

	T abs_diff = std::abs(a - b);
	T abs_a = std::abs(a);
	T abs_b = std::abs(b);
	T largest = std::max(abs_a, abs_b);

	// 2. Relative tolerance for large numbers
	// 3. Absolute tolerance for numbers near zero
	// Using 4x epsilon for a small safety buffer (typical ULP allowance)
	return abs_diff < (largest * epsilon * 4);
}

template<typename T>
bool is_less_than (T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
{
	// If a is significantly smaller than b, return true.
	// If they are "nearly equal" according to your tolerance, return false.
	return (a < b) && !are_nearly_equal(a, b, epsilon);
}

template<typename T>
bool is_less_than_or_equal(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) {
	return (a < b) || are_nearly_equal(a, b, epsilon);
}

template<typename T>
bool is_greater_than (T a, T b, T epsilon = std::numeric_limits<T>::epsilon())
{
	// If a is significantly smaller than b, return true.
	// If they are "nearly equal" according to your tolerance, return false.
	return (b < a) && !are_nearly_equal(b, a, epsilon);
}

template<typename T>
bool is_less_greater_or_equal(T a, T b, T epsilon = std::numeric_limits<T>::epsilon()) {
	return (b < a) || are_nearly_equal(b, a, epsilon);
}

struct Point {
	double x, y;
};

struct Planet {
	Point p;
	long long l;
};

int main()
{
	Point P, Q;
	cin >> P.x >> P.y >> Q.x >> Q.y;
	auto n = read<int>();
	auto C = vector<Planet>(n);
	for (auto &c : C)
		cin >> c.p.x >> c.p.y >> c.l;

	cout << fixed << setprecision(9);
	cout << sqrt((P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y)) << endl;

	auto left_n = 0, left_h = 0;
	auto right_n = 0, right_h = 0;
	auto broken = 0;

	auto V = Point{
		Q.x - P.x,
		Q.y - P.y
	};

	double zero = 0;

	for (auto &c : C)
	{
		auto W = Point{
			c.p.x - P.x,
			c.p.y - P.y
		};

		auto det = (V.x * W.y) - (W.x * V.y);

		if (is_less_than(det, zero))
			++right_n, right_h += c.l;
		else if (is_greater_than(det, zero))
			++left_n, left_h += c.l;
		else
			++broken;
	}

	cout << left_n << space << left_h << endl;
	cout << right_n << space << right_h << endl;
	cout << broken << endl;
}
