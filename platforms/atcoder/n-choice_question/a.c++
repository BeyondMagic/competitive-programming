#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        if (a + b == c)
        {
            cout << i << '\n';
            break;
        }
    }
}