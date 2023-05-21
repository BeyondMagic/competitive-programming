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

/* Grid of maximum numbers in prime grid. */
#define MIN_PRIMES 2
#define MAX_PRIMES 2000

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

/* Thanks https://vjudge.net/user/Thalisson for the macro definition. */
#define all(list) list.begin(), list.end()

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
  // TODO: Implement my own root algorithgm
  long double root (long double number, int64_t nth);

  namespace prime
  {

    // Algorithm: Sieve of Eratosthenes.
    // Complexity: O(n log(log(N)))
    template <size_t N>
    struct Sieve_of_Eratosthenes
    {
      constexpr Sieve_of_Eratosthenes() : table()
      {
        table[0] = table[1] = false;

        for (size_t i = 2; i < N; i++)
          table[i] = true;

        for (size_t i = 2; i < N; i++)
          if (table[i])
            for (size_t j = i * i; j < N; j += i)
              table[j] = false;
      }
      bool table[N];
    };

    constexpr bool is (const size_t number)
    {
       constexpr auto primes = Sieve_of_Eratosthenes<MAX_PRIMES + MIN_PRIMES>();

      return primes.table[number];

    }
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

int64_t powmod (int64_t a, int64_t b, int64_t p) {
  int64_t res = 1;
  while (b)
    // If it is even.
    if (b & 1)
      res = int64_t(res * 1ll * a % p), --b;
    // If it is odd.
    else
      a = int64_t(a * 1ll * a % p), b >>= 1;
  return res;
}

uint64_t generator (int64_t p) {
  vector<int64_t> fact;
  int64_t phi = p - 1,  n = phi;
  for (int64_t i = 2; i * i <= n; ++i)
    if (not (n % i)) {
      fact.push_back (i);
      while (not (n % i))
        n /= i;
    }
  if (n > 1)
    fact.push_back (n);

  uint64_t total = 0;
  for (int64_t res = 2; res <= p; ++res)
  {
    bool ok = true;
    for (size_t i = 0; i < fact.size(); ++i)
    {
      ok &= powmod(res, phi / fact[i], p) not_eq 1;
      if (ok)
      {
        ++total;
        ok = false;
      }
    }
  }
  return total;
}

// Complexity: O(sqrt(N)
constexpr size_t calculator (size_t p)
{
  // assume all primite primes are from 1 to p - 1
  size_t phi = p - 1, count = phi;

  for (size_t i = 2; i * i <= phi; ++i)
    // if phi is not identical 1 (mod P);
    if (not (phi % i))
    {
      // make it identical by dividing phi by i.
      // also reduce phi to run lower modular next iteration.
      do phi /= i; while (not (phi % i));
      // reduce count i - 1
      count = count / i * (i - 1);
    }

  // there's one more than it should be.
  // remove last (1) mod P number
  if (phi not_eq 1)
    count = count / phi * (phi - 1);

  return count;
}

// Algorithm: Sieve of Eratosthenes.
// Complexity: O(n log(log(N)))
template <size_t N>
struct Primitive_Roots
{
  constexpr Primitive_Roots() : table()
  {
    for (size_t i = 2; i <= N; ++i)
      if (math::prime::is(i))
        table[i] = calculator(i);
  }
  size_t table[N];
};


int main()
{
  FAST_IO;
  //OUT_PRECISION(6);

  /* input */
  uint64_t a;
  cin >> a;

  static constexpr auto roots = Primitive_Roots<MAX_PRIMES>();

  cout << roots.table[a] << endl;
}
