#include <bits/stdc++.h>

using namespace std;

int main ()
{
    scanf("%*d");
    string s;
    cin >> s;
    bool takashi = true; // takashi ganhou
    int T = 0, A = 0;
    for (const auto a : s)
    {
        if (a == 'T') {
            T++;
            if (T > A)
                takashi = true;
        } else {
            A++;
            if (T < A)
                takashi = false;
        }
    }

    if (T > A or (T == A and takashi))
        cout << "T\n";
    else if (T < A or (T == A and !takashi))
        cout << "A\n";

}