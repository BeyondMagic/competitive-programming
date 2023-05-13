#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> par(n), par_ordenado(n);
    cin >> par[0];
    for (int i = 1; i < n; i++)
    {
        cin >> par[i];
        par_ordenado[i] = par[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(par[i] - par[i + 1]) != 1)
        {
            if (par[i] < par[i + 1])
            {
                for (int s = par[i], si = 0; s < par[i+1]; s++, si++)
                {
                    par_ordenado.insert(par_ordenado.begin() + i + si, s);
                }
            }
            else if (par[i] > par[i + 1])
            {
                for (int s = par[i+1], si = 0; s > par[i]; s--, si++)
                    par_ordenado.insert(par_ordenado.begin() + i + si, s);
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