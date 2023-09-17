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
  char decimal_value(int64_t c)
  {
     if (c >= '0' && c <= '9')
        return char(c) - '0';
     else
        return char(c) - 'A' + 10;
  }

  char base_value(int64_t num)
  {
      if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
  }
  // converting number to decimal equivalent
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
    auto decimal = base_to_decimal(number, from);
    if (decimal < 0)
      return "";
    auto in_base = decimal_to_base(decimal, to);
    return in_base;
  }
}

/* calculation */
auto solve (int64_t from, int64_t to, string value)
{
  string result;
  if (size_t(count(value.begin(), value.end(), '0')) == value.size())
    result = "0";
  else
    result = math::from_base_to_base(from, to, value);

  if (result.empty())
  {
    cout << value << " is an illegal base " << from << " number" << endl;
    return;
  }

  cout << value << " base " << from << " = " << result << " base " << to << endl;
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
  int64_t a, b;
  string c;
  while (cin >> a >> b >> c)
    /* output */
    solve(a, b, c);
}
