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

/* Shortcut for long long. */
typedef long long ll;

/* No more std:: */
using namespace std;

/* NOTE: Perhaps we can implement ourselves into the STL.
 *       The question is whether it should be before the upper line or below it. */
namespace line {
  inline void erase_wall (string &str, const char &character)
  {
    str.erase(std::remove(str.begin(), str.end(), character), str.end());
  }
}

#define WIN "You win."
#define LOSE "You lose."
#define CHICKEN "You chickened out."

/* calculation */
auto solve (ll &round)
{
  cout << "Round " << round << endl;
  string word, next;
  cin >> word >> next;

  int strokes = 7;
  for (const auto c : next)
  {
    if (word.find(c) == string::npos)
      strokes--;
    else
      line::erase_wall(word, c);

    if (word.empty())
      return WIN;

    if (not strokes)
      return LOSE;
  };

  return CHICKEN;
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
  ll a = 0;
  while (cin >> a and a not_eq -1)
    /* output */
    cout << solve(a) << endl;
}
