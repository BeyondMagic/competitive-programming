#include <iostream>

using namespace std;

int main ()
{
    size_t n;
    cin >> n;
    string answer = "No";
    for (size_t i = 1; i <= n; i++)
    {
        char a;
        cin >> a;
        if (a == 'x')
        {
            answer = "No";
            break;
        } else if (a == 'o')
        {
            answer = "Yes";
        }
    }

    cout << answer << '\n';
}