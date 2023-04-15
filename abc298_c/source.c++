#include <bits/stdc++.h>

using namespace std;

static unordered_map<int, vector<int>> data;

void solve (int c)
{
    int i, j;
    switch (c)
    {
        case 1:
            cin >> i >> j;
            if (data.find(j) == data.end())
                data.insert({j, {i}});
            else
            {
                data.at(j).emplace_back(i);
            }
        break;

        // 2 and 3
        // in ascending order, with spaces in between.
        case 2:
            sort(begin(data.at(j)), end(data.at(j)));
            cin >> i;
            for (const auto e : data.at(i))
                cout << e << ' ';
            cout << '\n';
        break;
        case 3:
            cin >> i;
            vector<int> boxes;
            for (const auto e : data)
            {
                if (find(begin(e.second), end(e.second), i) != end(e.second))
                    boxes.emplace_back(e.first);
            }
            sort(begin(boxes), end(boxes));

            for (const auto e : boxes)
                cout << e << ' ';

            cout << '\n';
        break;
    }

}

int main ()
{
    int n;
    cin >> n;
    int c;
    while (cin >> c)
        solve(c);
}