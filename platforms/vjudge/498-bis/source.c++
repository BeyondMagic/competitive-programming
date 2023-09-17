#include <bits/stdc++.h>

/* https://stackoverflow.com/a/18429250 */
#define INF 0x3f3f3f3f

/* Set precision for output. */
#define PRECISION 6

/* Set precision for calculations. */
#define PRECISION_CALC 1e-10

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

/* Mathematical related structures and methods. */
namespace math
{
  /* Growing-ordered polynomial, so the first
   * is the highest degree to the last which is
   * the lowest degree. */
  using polynomial = vector<int64_t>;

  static inline size_t degree(const polynomial& p)
  {
    return p.size() - 1;
  }

  /* TODO: Turn this into an operator. */
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

/* calculation */
auto solve (int64_t x, math::polynomial &poly)
{
  math::derivate(poly);

  return math::evaluate(poly, x);
}

int main()
{
  /* desynchronize C and C++ io */
  //ios::sync_with_stdio(false);

  /* untie cin from cout */
  //cin.tie(NULL);

  /* output rules */
  //cout << fixed << setprecision(3);

  /* input */
  int64_t a;
  while (cin >> a)
  {
    scanf("\n");
    math::polynomial b(100'000);

    string line;
    getline(cin, line);

    istringstream is(line);
    int c;
    while (is >> c)
      b.emplace_back(c);

    /* output */
    cout << solve(a, b) << endl;
  }
}
