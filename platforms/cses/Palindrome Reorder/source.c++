#include "library.hpp"

using namespace std;


int main ()
{
    fast_io();
    auto s = read<string>();

    vector<int> counts(26, 0);
    for (char c : s) {
        counts[c - 'A']++;
    }

    string middle_char = "";
    int odd_counts = 0;
    for (int i = 0; i < 26; ++i) {
        if (counts[i] % 2 != 0) {
            odd_counts++;
            middle_char = (char)('A' + i);
        }
    }

    if (odd_counts > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string left = "";
    for (int i = 0; i < 26; ++i)
        left += string(counts[i] / 2, (char)('A' + i));

    auto right = string(left.rbegin(), left.rend());

    cout << left << middle_char << right << endl;

    return 0;
}
