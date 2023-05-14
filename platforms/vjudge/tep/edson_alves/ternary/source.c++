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

/* NOTE: Perhaps we can implement ourselves into the STL.
 *       The question is whether it should be before the upper line or below it. */

/* String related methods. */
namespace line
{
  inline void erase_wall (string &str, const char &character)
  {
    str.erase(std::remove(str.begin(), str.end(), character), str.end());
  }
}

namespace math
{
  using binary = string;

  char real_value(int64_t num)
  {
    if (num >= 0 && num <= 9)
      return char(num) + '0';
    else
      // NOTE: it assumes it will follow hexadecimal standard for the rest of characteres.
      return char(num - 10) + 'A';
  }

  // Convert a given decimal number to a base.
  binary to_decimal(int64_t &number, int64_t base)
  {
    binary answer;

    if (not number)
      return "0";

    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (number > 0)
    {
      answer.push_back(real_value(number % base));
      number /= base;
    }

    // Reverse the result
    reverse(answer.begin(), answer.end());

    return answer;
  }
}

/* calculation */
auto solve (int64_t n)
{
  return math::to_decimal(n, 3);
}

int main()
{
  /* desynchronize C and C++ io */
  ios::sync_with_stdio(false);

  /* untie cin from cout */
  cin.tie(NULL);

  /* output rules */
  cout << fixed << setprecision(0);

  /* input */
  int64_t a;
  while (cin >> a and a >= 0)
    /* output */
    cout << solve(a) << endl;
}
