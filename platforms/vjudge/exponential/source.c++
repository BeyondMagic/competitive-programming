#include <bits/stdc++.h>

/* https://stackoverflow.com/a/18429250 */
#define INF 0x3f3f3f3f

/* Set precision for calculations. */
#define PRECISION_CALC 1e-10

/* desynchronize C and C++ io */
#define DESYNC_IO ios::sync_with_stdio(false)

/* Untie cin from cout */
#define UNTIE_IO cin.tie(NULL)

/* Implement thw top two macros. */
#define FAST_IO DESYNC_IO; UNTIE_IO

/* Set precision for output. */
#define OUT_PRECISION(precision) cout << fixed << setprecision(precision)

/* Since the STL-implemented std::endl is not usually what we want:
 * flush and then print out a newline;
 * we just want to print the newline */
#define endl '\n'

/* Comparing operations to be used only with real numbers. */
#define EQUAL_DECIMAL_E(a, b, epsilon)   (fabs((a) - (b)) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))
#define GREATER_DECIMAL_E(a, b, epsilon) (((a) - (b)) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))
#define LESS_DECIMAL_E(a, b, epsilon)    (((b) - (a)) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * (epsilon)))

/* Comparing operations to be used only with real numbers. */
#define EQUAL_DECIMAL(a, b)   EQUAL_DECIMAL_E(a, b, PRECISION_CALC)
#define GREATER_DECIMAL(a, b) GREATER_DECIMAL_E(a, b, PRECISION_CALC)
#define LESS_DECIMAL(a, b)    LESS_DECIMAL_E(a, b, PRECISION_CALC)

/* Maximum number from two doubles. */
#define MAX_DECIMAL(a, b, epsilon) (GREATER_DECIMAL(a, b, epsilon) ? (a) : (b)))
#define MIN_DECIMAL(a, b, epsilon) (LESS_DECIMAL(a, b, epsilon) ? (a) : (b)))

/* No more std:: */
using namespace std;

/* String related methods. */
namespace line
{
  inline void erase_wall (string &str, const char &character)
  {
    str.erase(std::remove(str.begin(), str.end(), character), str.end());
  }
}

/* For mathematical structures and methods. */
namespace math
{
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

    /* FIXIT: Need testing. It's possible this method does not sum correctly the polynomial terms. */
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

/* calculation */
auto solve (size_t max)
{
  vector<size_t> expo(max + 2);

  expo.at(1) = 1;
  for (size_t nth = 2; nth <= max; ++nth)
    for (size_t power = nth * nth; power <= max; power *= nth)
      expo.at(power) = 1;

  for (size_t i = max; i >= 1; --i)
    if (expo.at(i))
      return i;

  return max;
}

int main()
{
  FAST_IO;
  //OUT_PRECISION(6);

  /* input */
  size_t a;
  cin >> a;

  /* output */
  cout << solve(a) << endl;
}
