#include <iostream>
#include <array>

using namespace std;

int main ()
{
    size_t n;
    cin >> n;
    array<array<size_t, 100>, 100> a, b;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            cin >> a.at(n + 1 - j).at(i);

    string answer = "Yes";
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> b.at(i).at(j);
            if (a.at(i).at(j) == 1)
            {
                if (b.at(i).at(j) != a.at(i).at(j))
                {
                    cout << "No";
                    return 0;
                } else {
                    answer = "Yes";
                }
            }
        }
    }

    cout << answer << '\n';
}