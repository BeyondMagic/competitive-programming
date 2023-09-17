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
  // returning values of a character
  int64_t real_value(char c)
  {
     if (c >= '0' && c <= '9')
        return int64_t(c) - '0';
     else
        return int64_t(c) - 'A' + 10;
  }
  // converting number to decimal equivalent
  int64_t base_to_decimal (string str, int64_t base)
  {
     int64_t power = 1;
     int64_t num = 0;

     for (int64_t i = int64_t(str.size()) - 1; i >= 0; i--)
     {
        if (real_value(str[size_t(i)]) >= base)
           return -1;
        num += real_value(str[size_t(i)]) * power;
        power = power * base;
     }
     return num;
  }
}

/* calculation */
auto solve (string x, string y)
{
  int64_t decimal_x,
          decimal_y;

  for (int64_t i = 2; i <= 36; i++) // for
  {
    decimal_x = math::base_to_decimal(x, i);
    if (decimal_x < 0)
      continue;

    for (int64_t j = 2; j <= 36; j++) // for y
    {
      decimal_y = math::base_to_decimal(y, j);
      if (decimal_y < 0)
        continue;

      if (decimal_x == decimal_y)
      {
        cout << x << " (base " << i << ") = " << y << " (base " << j << ")" << endl;
        return;
      }
    }
  }
  cout << x << " is not equal to " << y << " in any base 2..36" << endl;
}

int main()
{
  /* desynchronize C and C++ io */
  ios::sync_with_stdio(false);

  /* untie cin from cout */
  cin.tie(NULL);

  /* output rules */
  cout << fixed << setprecision(3);

  /* input */
  string a, b;
  while (cin >> a >> b)
    /* output */
    solve(a, b);
}
