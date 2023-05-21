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

using namespace std;

/* calculation */
auto solve (int a, int b, int c)
{
  if (LESS_DECIMAL(a, 0.))
  {
    b = -b;
    c = -c;
    a = -a;
  }
  if (!a)
  {
    if (!b)
      if (c)
        cout << -1 << endl;
      else
        cout << 0 << endl;
    else
      cout << c/b;
    return;
  }

  double d = ((double)b * (double)b) - 4. * (double) a * (double) c;

  if (EQUAL_DECIMAL(d, 0.))
  {
    cout << 1 << endl;
    cout << -b / (2l*a) << endl;
  }
  else if (GREATER_DECIMAL(d, 0.))
  {
    cout << 2 << endl;

    auto x1 = (-b - sqrt(d)) / (2.*a);
    auto x2 = (-b + sqrt(d)) / (2.*a);
    if (GREATER_DECIMAL(x1, x2))
      swap(x1, x2);

    cout << x1 << endl;
    cout << x2 << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}

auto solve2 (int a, int b, int c)
{
  double delta = b * b - 4. * a * c;
  if (not a)
  {
    if (not a and not c)
      cout << -1;
    else if (not b)
      cout << 0;
    else if (not c)
      cout << 1 << endl << 0.;
    else
      cout << 1 << -1. * (double) c / (double) b;
  }
  else if (not b and not c)
  {
    cout << 1 << endl << 0.;
  }
  else if (LESS_DECIMAL(delta, 0.))
    cout << 0;
  else if (EQUAL_DECIMAL(delta, 0.))
    cout << 1 << endl << 1./2. * (double) b / (double) a;
  else
  {
    cout << 2 << endl;
    double x1 = 1./2. / (double) a * (- (double) b - sqrt(delta));
    double x2 = 1./2. / (double) a * (sqrt(delta) - (double) b);

    if (a < 0)
      swap(x1, x2);

    cout << x1 << endl << x2;
  }

  cout << endl;
}

auto solve3 (int a, int b, int c)
{
  double A = (double) a,
         B = (double) b,
         C = (double) c;
  if (not a)
  {
    if (not b)
    {
      if (not c)
        cout << -1 << endl;
      else
        cout << 0 << endl;
      return;
    }
    cout << 1 << endl;
    cout << -C / B;
    return;
  }

  double h = b * b - 4 * a * c;
  if (LESS_DECIMAL(h, 0.))
  {
    cout << 0 << endl;
    return;
  }

  if (EQUAL_DECIMAL(h, 0.))
  {
    cout << 1 << endl;
    cout << -B / (2.0 * A);
  } else {
    cout << 2 << endl;
    double H = sqrt( (double) h);
    double x1 = (-B - H) / (2.0 * A);
    double x2 = (-B + H) / (2.0 * A);

    cout << min(x1, x2) << endl;
    cout << max(x1, x2) << endl;
  }
}

auto solve4 (ll a, ll b, ll c)
{
  if (b*b < 4*a*c)
    cout << 0 << endl;
  else if (not a)
  {
    if (not c and not b)
      cout << -1 << endl;
    else if (not b)
      cout << 0 << endl;
    else
      cout << 1 << endl << - double(c) / double(b) << endl;
  }
  else
  {
    if (b * b == 4 * a * c)
      cout << 1 << endl << -1.0 * double(b) / (2.0 * double(a));
    else
    {
      cout << 2 << endl;
      double x1 = (-1.0 * double(b) + sqrt(double(b * b - 4 * a * c))) / (2.0 * double(a));
      double x2 = (-1.0 * double(b) - sqrt(double(b * b - 4 * a * c))) / (2.0 * double(a));
      cout << min(x1, x2) << endl;
      cout << max(x1, x2) << endl;
    }
  }
}

int main()
{
  /* desynchronize C and C++ io */
  ios::sync_with_stdio(false);

  /* untie cin from cout */
  cin.tie(NULL);

  /* output rules */
  cout << fixed << setprecision(PRECISION);

  /* input */
  ll a, b, c;
  cin >> a >> b >> c;

  /* output */
  solve4(a, b, c);
}
