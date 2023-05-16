#include <bits/stdc++.h>

using namespace std;

static int h, w;

namespace shift
{
    void vertical (vector<vector<char>> &map)
    {
        rotate(map.begin(), map.begin() + 1, map.end());
    }

    void horizontal (vector<vector<char>> &map)
    {
        for (auto &row: map) // move columns to the left
        {
            rotate(row.begin(), row.begin() + 1, row.end());
        }
    }
}

void is_equal (vector<vector<char>> &a, vector<vector<char>> &b)
{
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (a.at(i).at(j) != b.at(i).at(j))
                return;
    cout << "Yes\n";
    exit(0);
}

void read_vector (vector<vector<char>> &a)
{
    char t;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> t;
            a.at(i).emplace_back(t);
        }
}

void print_vector (vector<vector<char>> &a)
{
    for (const auto i : a)
    {
        for (const auto j : i)
            cout << j;
        cout << '\n';
    }
}

int main ()
{
    cin >> h >> w;

    vector<vector<char>> a(h), b(h);
    
    for (int i = 0; i < h; i++)
    {
        a.at(i).reserve(w);
        b.at(i).reserve(w);
    }

    // leitura
    read_vector(a);
    read_vector(b);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            shift::vertical(a);
            is_equal(a, b);
        }
        shift::horizontal(a);
        is_equal(a, b);
    }
    
    cout << "No\n";
}