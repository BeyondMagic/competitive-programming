#include <iostream>
#include <iomanip>
#include <array>    
#include <algorithm>
#include <numeric>

using namespace std;

double solve (int line, char operation, array<array<double, 12UL>, 12> &matrix)
{
    // sum
    if (operation == 'S')
    {
        double sum = 0;
        for (int i = 0; i < 12; i++)
            sum += matrix.at(line).at(i);
        return sum;
    }
    // average
    else
    {

    }
}

int main ()
{
    int l;
    cin >> l;
    char t;
    cout << fixed << setprecision(1);
    static array<array<double, 12>, 12> m;
    for (auto i = 1; i <= 12; i++)
        for (auto j = 1; j <= 12; j++)
            cin >> m.at(i).at(j);

    cout << solve(l, t, m) << '\n';
}