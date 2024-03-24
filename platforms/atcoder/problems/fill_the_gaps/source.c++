#include <bits/stdc++.h>
#include <debug.hpp>

using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> par(n), par_ordenado(n);
    cin >> par[0];
    par_ordenado[0] = par[0];
    for (int i = 1; i < n; i++)
    {
        cin >> par[i];
        par_ordenado[i] = par[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        const auto first = par[i];
        const auto last  = par[i+1];

        if (abs(first - last) != 1)
        {
            if (first < last)
                for (int s = first + 1, si = 0; s < last; s++, si++)
                    par_ordenado.insert(par_ordenado.begin() + i + si + 1, s);
            else if (first > last)
            {
                cout << "AAAAAA\n";
                for (int s = last - 1, si = 0; s > first; s--, si++)
                {
                    cout << "valor aaa: " << s << "\n";
                    par_ordenado.insert(par_ordenado.begin() + i + si + 1, s);
                }
            }
        }
    }

    for (auto it = par_ordenado.begin(); it != par_ordenado.end(); it++)
    {
        cout << *it;
        if (it + 1 != par_ordenado.end())
            cout << ' ';
    }
    cout << '\n';
}
